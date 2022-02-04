#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;
using namespace sway::core;

class HierarchyChildTraverser : public utils::Traverser {
public:
	OVERRIDE(u32_t visit(utils::Visitable * node)) {
		return detail::toUnderlying(utils::Traverser::Action::CONTINUE);
	}
};

BOOST_AUTO_TEST_SUITE(Hierarchy_TestSuite)

BOOST_AUTO_TEST_CASE(Hierarchy_TestCase) {
	foundation::Context * ctx = new foundation::Context();
	container::Hierarchy * tree = new container::Hierarchy();
	container::Node * root = new container::Node(ctx, nullptr, container::NodeIdx({ 0 }));

	tree->setRootNode(root);

	container::Node * child1 = new container::Node(ctx, root, container::NodeIdx());
	root->addChild(child1);
	//BOOST_CHECK_EQUAL(std::to_string<container::NodeIdx>(child1->getNodeIdx()), "[0, 0]");

	container::Node * child2 = new container::Node(ctx, root, container::NodeIdx());
	root->addChild(child2);
	//BOOST_CHECK_EQUAL(std::to_string<container::NodeIdx>(child2->getNodeIdx()), "[0, 1]");

	HierarchyChildTraverser traverser;
	root->traverse(&traverser);

	SAFE_DELETE(tree);
}

BOOST_AUTO_TEST_SUITE_END()
