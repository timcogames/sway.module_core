#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

#include <sstream>  // std::stringstream
#include <vector>

#define NODE_IDX_SUPERVISOR (0)
#define NODE_IDX_WORKER (1)

NS_SHORT_SWAY()
NS_SHORT(core)

class NodeIndexTest : public testing::Test {
public:
#pragma region "Override Test methods"

  void SetUp() override {
    /**
     *    ROOT (-1)
     *    └── SUPERVISOR (0)
     *         └── WORKER (1)
     */
    root_ = NodeIndex(NODEIDX_CHAIN_INITIALROOT);
    supervisor_ = NodeIndex(root_, NODE_IDX_SUPERVISOR);
    worker_ = NodeIndex(supervisor_, NODE_IDX_WORKER);
  }

  void TearDown() override {}

#pragma endregion

  NodeIndex root_;
  NodeIndex supervisor_;
  NodeIndex worker_;
};

TEST_F(NodeIndexTest, equality) {
  EXPECT_TRUE(worker_.equal(NodeIndex({NODEIDX_ROOT, NODE_IDX_SUPERVISOR, NODE_IDX_WORKER})));
}

TEST_F(NodeIndexTest, to_str) {
  std::stringstream stream;
  stream << "[" << NODEIDX_ROOT << ", " << NODE_IDX_SUPERVISOR << ", " << NODE_IDX_WORKER << "]";
  ASSERT_STREQ(worker_.toStr().c_str(), stream.str().c_str());
}

TEST_F(NodeIndexTest, get_match_depth) {
  std::vector<i32_t> v1 = {-1, 0, 2};
  std::vector<i32_t> v2 = {-1, 0, 2, 1};

  auto result = NodeIndex::getMatchDepth(v1, v2);
  ASSERT_EQ(result, 3);
}
