#include <sway/core/generic/io/path.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_ALIAS(io_, core::generic::io)

TEST(PathTest, get_filepath_info) {
  const auto filepath = io_::Path("/foo/bar.txt");
  ASSERT_STREQ(filepath.getFilename().c_str(), "bar.txt");
  ASSERT_STREQ(filepath.getExt().c_str(), "txt");
}
