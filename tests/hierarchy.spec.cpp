#include <boost/test/unit_test.hpp>
#include <sway/core.h>

using namespace sway;
using namespace core::containers;

class HierarchyChildTraverser
	: public IHierarchyTraverser {

public:
	virtual TraversalAction_t visit(HierarchyNode * node) override {
		return TraversalAction_t::Continue;
	}
};

BOOST_AUTO_TEST_SUITE(Hierarchy_TestSuite)

BOOST_AUTO_TEST_CASE(Hierarchy_TestCase) {
	Hierarchy * tree = new Hierarchy();
	HierarchyNode * root = new HierarchyNode(nullptr, HierarchyNodeIdx({ 0 }), "root");

	tree->setRootNode(root);

	HierarchyNode * child1 = new HierarchyNode(root, HierarchyNodeIdx(), "child1");
	root->addChild(child1);
	BOOST_CHECK_EQUAL(std::to_string<HierarchyNodeIdx>(child1->getNodeIdx()), "[0, 0]");

	HierarchyNode * child2 = new HierarchyNode(root, HierarchyNodeIdx(), "child2");
	root->addChild(child2);
	BOOST_CHECK_EQUAL(std::to_string<HierarchyNodeIdx>(child2->getNodeIdx()), "[0, 1]");

	HierarchyChildTraverser traverser;
	root->traverse(&traverser);

	SAFE_DELETE(tree);
}

BOOST_AUTO_TEST_SUITE_END()
