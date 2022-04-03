#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(PathTest, getFilename) { ASSERT_STREQ(core::generic::io::Path("/foo/bar.txt").getFilename().c_str(), "bar.txt"); }

TEST(PathTest, getExtension) { ASSERT_STREQ(core::generic::io::Path("/foo/bar.txt").getExt().c_str(), "txt"); }
