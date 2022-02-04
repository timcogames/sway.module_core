#include <boost/test/unit_test.hpp>
#include <sway/core.h>

using namespace sway;

class HierarchyChildTraverser
	: public utils::ITraverser {

public:
	virtual utils::TraversalAction visit(containers::Node * node) override {
		return utils::TraversalAction::Continue;
	}
};

BOOST_AUTO_TEST_SUITE(Hierarchy_TestSuite)

BOOST_AUTO_TEST_CASE(Hierarchy_TestCase) {
	foundation::Context * ctx = new foundation::Context();
	containers::Hierarchy * tree = new containers::Hierarchy();
	containers::Node * root = new containers::Node(ctx, nullptr, containers::NodeIdx({ 0 }));

	tree->setRootNode(root);

	containers::Node * child1 = new containers::Node(ctx, root, containers::NodeIdx());
	root->addChild(child1);
	//BOOST_CHECK_EQUAL(std::to_string<containers::NodeIdx>(child1->getNodeIdx()), "[0, 0]");

	containers::Node * child2 = new containers::Node(ctx, root, containers::NodeIdx());
	root->addChild(child2);
	//BOOST_CHECK_EQUAL(std::to_string<containers::NodeIdx>(child2->getNodeIdx()), "[0, 1]");

	HierarchyChildTraverser traverser;
	root->traverse(&traverser);

	SAFE_DELETE(tree);
}

BOOST_AUTO_TEST_SUITE_END()
