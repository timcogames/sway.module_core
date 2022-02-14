#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

class HierarchyChildTraverser : public utils::Traverser {
  public:
    MTHD_OVERRIDE(u32_t visit(utils::Visitable *node)) {
        return detail::toUnderlying(utils::Traverser::Action::CONTINUE);
    }
};

TEST(HierarchyTest, Base) {
    foundation::Context *ctx = new foundation::Context();
    container::Hierarchy *tree = new container::Hierarchy();
    std::shared_ptr<container::Node> root = std::make_shared<container::Node>();

    tree->setRootNode(root);

    std::shared_ptr<container::Node> child1 = std::make_shared<container::Node>();
    root->addChildNode(child1);
    ASSERT_STREQ(child1->getNodeIdx().toStr().c_str(), "[-1, 0]");

    std::shared_ptr<container::Node> child2 = std::make_shared<container::Node>();
    root->addChildNode(child2);
    ASSERT_STREQ(child2->getNodeIdx().toStr().c_str(), "[-1, 1]");

    HierarchyChildTraverser traverser;
    root->traverse(&traverser);

    SAFE_DELETE(tree);
}
