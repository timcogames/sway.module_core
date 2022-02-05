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
	std::shared_ptr<container::Node> root = std::make_shared<container::Node>();

	tree->setRootNode(root);

	std::shared_ptr<container::Node> child1 = std::make_shared<container::Node>();
	root->addChildNode(child1);
	//BOOST_CHECK_EQUAL(std::to_string<container::NodeIdx>(child1->getNodeIdx()), "[0, 0]");

	std::shared_ptr<container::Node> child2 = std::make_shared<container::Node>();
	root->addChildNode(child2);
	//BOOST_CHECK_EQUAL(std::to_string<container::NodeIdx>(child2->getNodeIdx()), "[0, 1]");

	HierarchyChildTraverser traverser;
	root->traverse(&traverser);

	SAFE_DELETE(tree);
}

BOOST_AUTO_TEST_SUITE_END()
