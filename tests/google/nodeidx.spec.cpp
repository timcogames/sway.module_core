#include <sway/core/container/node.hpp>

#include <gtest/gtest.h>

#include <sstream>  // std::stringstream

#define NODE_IDX_SUPERVISOR (0)
#define NODE_IDX_WORKER (1)

using namespace sway::core::container;

class NodeIdxTest : public ::testing::Test {
  public:
    MTHD_OVERRIDE(void SetUp()) {
        /*!
         *    ROOT (-1)
         *    └── SUPERVISOR (0)
         *         └── WORKER (1)
         */
        root_ = NodeIdx(NODEIDX_CHAIN_INITIALROOT);
        supervisor_ = NodeIdx(root_, NODE_IDX_SUPERVISOR);
        worker_ = NodeIdx(supervisor_, NODE_IDX_WORKER);
    }
    MTHD_OVERRIDE(void TearDown()) {}

    NodeIdx root_;
    NodeIdx supervisor_;
    NodeIdx worker_;
};

TEST_F(NodeIdxTest, Equality) {
    EXPECT_TRUE(worker_.equal(NodeIdx({NODEIDX_ROOT, NODE_IDX_SUPERVISOR, NODE_IDX_WORKER})));
}

TEST_F(NodeIdxTest, ToStr) {
    std::stringstream stream;
    stream << "[" << NODEIDX_ROOT << ", " << NODE_IDX_SUPERVISOR << ", " << NODE_IDX_WORKER << "]";
    ASSERT_STREQ(worker_.toStr().c_str(), stream.str().c_str());
}

TEST_F(NodeIdxTest, getMatchDepth) {
    std::vector<int> v1 = {-1, 0, 2};
    std::vector<int> v2 = {-1, 0, 2, 1};

    auto result = NodeIdx::getMatchDepth(v1, v2);
    ASSERT_EQ(result, 3);
}
