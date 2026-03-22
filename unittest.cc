// Unittests for GGGG.

#include <filesystem>
#include <string>
#include <vector>

#include <assert.h>
#include <stdlib.h>

#include <gtest/gtest.h>

#include "copyfile.h"
#include "decode.h"

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
