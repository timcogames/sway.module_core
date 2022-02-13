#include <sway/core/container/node.hpp>

#include <gtest/gtest.h>

#include <sstream>  // std::stringstream

#define NODE_IDX_SUPERVISOR (0)
#define NODE_IDX_WORKER (1)

using namespace sway::core::container;

class NodeIdxTest : public ::testing::Test {
  public:
    NodeIdxTest() {}
    ~NodeIdxTest() = default;

    void SetUp() {
        /*!
         *    ROOT (-1)
         *    └── SUPERVISOR (0)
         *         └── WORKER (1)
         */
        root_ = NodeIdx(NODEIDX_CHAIN_INITIALROOT);
        supervisor_ = NodeIdx(root_, NODE_IDX_SUPERVISOR);
        worker_ = NodeIdx(supervisor_, NODE_IDX_WORKER);
    }
    void TearDown() {}

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
