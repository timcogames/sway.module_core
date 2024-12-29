#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/util/traverser.hpp>
#include <sway/core/util/traverseractions.hpp>
#include <sway/core/util/visitable.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

NS_SHORT_SWAY()
NS_SHORT(core)

class HierarchyTest : public testing::Test {
public:
#pragma region "Overridden Test methods"

  void SetUp() override { hierarchy_ = new Hierarchy(); }

  void TearDown() override { delete hierarchy_; }

#pragma endregion

  HierarchyTypedefs::Ptr_t hierarchy_;
};

class HierarchyChildTraverser : public util::Traverser {
public:
#pragma region "Overridden Traverser methods"

  MTHD_VIRTUAL_OVERRIDE(auto visit([[maybe_unused]] util::Visitable::Ptr_t node) -> u32_t) {
    return detail::toBase(util::TraverserAction::Enum::CONTINUE);
  }

#pragma endregion
};

TEST_F(HierarchyTest, set_root_node) {
  auto root = std::make_shared<Node>();
  hierarchy_->setRootNode(root);
  ASSERT_STREQ(hierarchy_->getRootNode()->getNodeIndex().toStr().c_str(), "[-1]");
}

TEST_F(HierarchyTest, add_child_node) {
  auto child1 = std::make_shared<Node>();
  hierarchy_->getRootNode()->addChildNode(child1);
  ASSERT_STREQ(child1->getNodeIndex().toStr().c_str(), "[-1, 0]");

  auto child2 = std::make_shared<Node>();
  hierarchy_->getRootNode()->addChildNode(child2);
  ASSERT_STREQ(child2->getNodeIndex().toStr().c_str(), "[-1, 1]");
}

TEST_F(HierarchyTest, find_node) {
  auto child = std::make_shared<Node>();
  hierarchy_->getRootNode()->addChildNode(child);

  auto found = hierarchy_->findNode(hierarchy_->getRootNode(), NodeIndex(std::vector<int>({-1, 0})));
  ASSERT_STREQ(found->get()->getNodeIndex().toStr().c_str(), "[-1, 0]");
}
