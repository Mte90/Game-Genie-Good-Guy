// Unittests for GGGG.

#define _POSIX_C_SOURCE 200809L

#include <filesystem>
#include <string>
#include <vector>

#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#include <gtest/gtest.h>

#include "copyfile.h"
#include "decode.h"
#include "modify.h"

namespace fs = std::filesystem;

namespace {

// Utility class that creates a unique tmpdir for every test.
class TempDirTest : public ::testing::Test {
 protected:
  fs::path tmpdir_;

  TempDirTest() {
    tmpdir_ = fs::temp_directory_path() / "gggg-tests.XXXXXX";
    std::string tmpdir = tmpdir_.string();
    EXPECT_NE(mkdtemp(tmpdir.data()), nullptr);
    tmpdir_ = tmpdir;
  }

  ~TempDirTest() {
    fs::remove_all(tmpdir_);
  }

  fs::path getTmpFile() {
    fs::path p = tmpdir_ / "tmp.XXXXXX";
    std::string s = p.string();
    int fd = mkstemp(s.data());
    EXPECT_NE(fd, -1);
    close(fd);
    p = s;
    return p;
  }
};

TEST_F(TempDirTest, CopyFile) {
  auto src = getTmpFile();
  auto dst = getTmpFile();
  fs::resize_file(src, 100);
  ASSERT_EQ(unlink(dst.c_str()), 0);
  ASSERT_EQ(gCopyFile(src.c_str(), dst.c_str(), true), true);
  ASSERT_EQ(fs::file_size(dst), 100);
}

class ModifyRomTest : public TempDirTest {
 protected:
  int getDataFile(size_t len, unsigned char fill = 0xAA) {
    // Get a tempfile of the correct length.
    auto file = getTmpFile();
    fs::resize_file(file, len);
    int fd = open(file.c_str(), O_RDWR);
    if (fd < 0)
      return -1;

    // Fill the file with non-zero data.
    void *map = mmap(nullptr, len, PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == nullptr)
      return -1;
    memset(map, fill, len);
    munmap(map, len);

    return fd;
  }

  int getSnesLoRom(bool header = true) {
    // Get a tempfile of the correct length.
    int pad = header ? 512 : 0;
    int fd = getDataFile(0x100000 + pad);
    if (fd < 0)
      return fd;

    // Write the LoROM header.  For now we write enough for our code,
    // but this probably should be a bit more complete.
    char c = 0x30;
    if (pwrite(fd, &c, 1, 0x7FD5 + pad) != 1)
      return -1;

    return fd;
  }
};

TEST_F(ModifyRomTest, NES) {
  struct codebits decoded;
  int fd = getDataFile(0x20010);
  ASSERT_GE(fd, 0);
  char c;

  c = 0x06;
  ASSERT_EQ(pwrite(fd, &c, 1, 0x73DD), 1);

  // Apply code and verify the rom data is updated.
  ASSERT_TRUE(decodeNES("OSKUILTA", &decoded));
  ASSERT_TRUE(modifyNES(fd, &decoded));
  ASSERT_EQ(pread(fd, &c, 1, 0x73DD), 1);
  ASSERT_EQ(c, '\xD1');

  // Verify other fields were not changed.
  ASSERT_EQ(pread(fd, &c, 1, 0x13DD), 1);
  ASSERT_EQ(c, '\xAA');
  ASSERT_EQ(pread(fd, &c, 1, 0x33DD), 1);
  ASSERT_EQ(c, '\xAA');
  ASSERT_EQ(pread(fd, &c, 1, 0x53DD), 1);
  ASSERT_EQ(c, '\xAA');
}

TEST_F(ModifyRomTest, SNES) {
  struct codebits decoded;
  int fd = getSnesLoRom();
  ASSERT_GE(fd, 0);
  char c;

  // Apply code and verify the rom data is now 0.
  ASSERT_TRUE(decodeSNES("DDA7AD65", &decoded));
  ASSERT_TRUE(modifySNES(fd, &decoded));
  ASSERT_EQ(pread(fd, &c, 1, 0xD132), 1);
  ASSERT_EQ(c, 0);

  // Apply code and verify the rom data is now 0.
  ASSERT_TRUE(decodeSNES("DD350761", &decoded));
  ASSERT_TRUE(modifySNES(fd, &decoded));
  ASSERT_EQ(pread(fd, &c, 1, 0xEB7E), 1);
  ASSERT_EQ(c, 0);
}

}

namespace {

void decode_tests(
    const std::vector<std::string> &codes,
    const std::vector<struct codebits> &exp,
    bool (*decoder)(const char *code, struct codebits *decoded)
)
{
  struct codebits decoded;
  for (size_t i = 0; i < codes.size(); ++i) {
    std::string code = codes[i];
    std::erase(code, '-');
    //codes[i].erase(std::remove(codes[i].begin(), codes[i].end(), '-'), codes[i].end());
    EXPECT_TRUE(decoder(code.c_str(), &decoded));
    EXPECT_EQ(exp[i].len, decoded.len);
    EXPECT_EQ(exp[i].off, decoded.off);
    EXPECT_EQ(exp[i].rep, decoded.rep);
    EXPECT_EQ(exp[i].cmp, decoded.cmp);
  }
}

TEST(Decode, Raw) {
  std::vector<std::string> codes = {
    "00:00",
    "ff:ab",
    "12345678:ee",
    "abcd=12",
    "4567=89?bb",
  };
  std::vector<struct codebits> exp = {
    {0, 0, 0, 0},
    {0, 0xff, 0xab, 0},
    {0, 0x12345678, 0xee, 0},
    {0, 0xabcd, 0x12, 0},
    {0, 0x4567, 0xbb, 0x89},
  };
  decode_tests(codes, exp, decodeRaw);
}

TEST(Decode, GbGgMs) {
  std::vector<std::string> codes = {
    "000-FEF-080",
  };
  std::vector<struct codebits> exp = {
    {9, 0xfe, 0, 0xba},
  };
  decode_tests(codes, exp, decodeGbGgMs);
}

TEST(Decode, Genesis) {
  std::vector<std::string> codes = {
    "AJDV-4A4L",
    "963B-4JAC",
  };
  std::vector<struct codebits> exp = {
    {8, 0x1d074a, 0x6002, 0},
    {8, 0x1d3202, 0x4ff, 0},
  };
  decode_tests(codes, exp, decodeGenesis);
}

TEST(Decode, NES) {
  std::vector<std::string> codes = {
    "SZEKKIVG",
  };
  std::vector<struct codebits> exp = {
    {8, 0x4d0c, 0xa5, 0xc6},
  };
  decode_tests(codes, exp, decodeNES);
}

TEST(Decode, SNES) {
  std::vector<std::string> codes = {
    "DDA7-AD65",
  };
  std::vector<struct codebits> exp = {
    {8, 0x1cf32, 0, 0},
  };
  decode_tests(codes, exp, decodeSNES);
}

}
