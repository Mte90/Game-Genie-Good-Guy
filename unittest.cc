// Unittests for GGGG.

#include <filesystem>
#include <string>

#include <assert.h>
#include <stdlib.h>

#include <gtest/gtest.h>

#include "copyfile.h"

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
