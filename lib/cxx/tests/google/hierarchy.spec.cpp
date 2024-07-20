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

class HierarchyChildTraverser : public util::Traverser {
public:
  MTHD_OVERRIDE(u32_t visit([[maybe_unused]] util::Visitable *node)) {
    return detail::toBase(util::Traverser::Action::CONTINUE);
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
