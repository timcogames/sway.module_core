#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

class HierarchyTest : public testing::Test {
  public:
    MTHD_OVERRIDE(void SetUp()) { hierarchy_ = new container::Hierarchy(); }

    MTHD_OVERRIDE(void TearDown()) { delete hierarchy_; }

    container::Hierarchy *hierarchy_;
};

class HierarchyChildTraverser : public utils::Traverser {
  public:
    MTHD_OVERRIDE(u32_t visit([[maybe_unused]] utils::Visitable *node)) {
        return detail::toUnderlying(utils::Traverser::Action::CONTINUE);
    }
};

TEST_F(HierarchyTest, setRootNode) {
    auto root = std::make_shared<container::Node>();
    hierarchy_->setRootNode(root);
    ASSERT_STREQ(hierarchy_->getRootNode()->getNodeIdx().toStr().c_str(), "[-1]");
}

TEST_F(HierarchyTest, addChildNode) {
    auto child1 = std::make_shared<container::Node>();
    hierarchy_->getRootNode()->addChildNode(child1);
    ASSERT_STREQ(child1->getNodeIdx().toStr().c_str(), "[-1, 0]");

    auto child2 = std::make_shared<container::Node>();
    hierarchy_->getRootNode()->addChildNode(child2);
    ASSERT_STREQ(child2->getNodeIdx().toStr().c_str(), "[-1, 1]");
}

TEST_F(HierarchyTest, findNode) {
    auto child = std::make_shared<container::Node>();
    hierarchy_->getRootNode()->addChildNode(child);

    auto found = hierarchy_->findNode(hierarchy_->getRootNode(), container::NodeIdx(std::vector<int>({-1, 0})));
    ASSERT_STREQ(found->get()->getNodeIdx().toStr().c_str(), "[-1, 0]");
}

TEST_F(HierarchyTest, getMatchDepth) {
    std::vector<int> v1 = {-1, 0, 2};
    std::vector<int> v2 = {-1, 0, 2, 1};

    auto result = container::Hierarchy::getMatchDepth(v1, v2);
    ASSERT_EQ(result, 3);
}

TEST_F(HierarchyTest, parse) {
    container::NodeDataList dataItems = {
        {{-1, 1}, "test_0"}, {{-1, 0, 1}, "test_1"}, {{-1, 0, 0}, "test_0_0"}, {{-1, 0, 0, 2}, "test_0_1"}};
    container::Hierarchy::parse(hierarchy_->getRootNode(), dataItems);

    printf("[ROOT   ]: childnodes (%i)\n", hierarchy_->getRootNode()->getNumOfChildNodes());
}
