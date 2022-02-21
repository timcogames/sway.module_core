#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

class HierarchyChildTraverser : public utils::Traverser {
  public:
    MTHD_OVERRIDE(u32_t visit([[maybe_unused]] utils::Visitable *node)) {
        return detail::toUnderlying(utils::Traverser::Action::CONTINUE);
    }
};

TEST(HierarchyTest, Base) {
    auto *tree = new container::Hierarchy();

    // auto root = std::make_shared<container::Node>();
    // tree->setRootNode(root);

    auto child1 = std::make_shared<container::Node>();
    tree->getRootNode()->addChildNode(child1);
    ASSERT_STREQ(child1->getNodeIdx().toStr().c_str(), "[-1, 0]");

    auto child2 = std::make_shared<container::Node>();
    tree->getRootNode()->addChildNode(child2);
    ASSERT_STREQ(child2->getNodeIdx().toStr().c_str(), "[-1, 1]");

    HierarchyChildTraverser traverser;
    tree->getRootNode()->traverse(&traverser);

    SAFE_DELETE(tree);
}
