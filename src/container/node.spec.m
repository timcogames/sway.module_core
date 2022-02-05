#import <XCTest/XCTest.h>
#import <sway/core/container/nodeidx.hpp>
#import <sway/core/container/node.hpp>
#import <sstream>
#import <stdio.h>

using namespace sway;
using namespace core::container;

@interface xctestcase_commons_Node : XCTestCase
	- (void)addSupervisor;
	- (void)addDoctorToSupervisor;
	- (void)addInternCollectionToDoctor;

@end

#define IDX_INTERN_A (0)
#define IDX_INTERN_B (1)
#define IDX_INTERN_C (2)

const std::initializer_list<std::string> InternNameList = { "intern_a", "intern_b", "intern_c" };

@implementation xctestcase_commons_Node {
	std::shared_ptr<Node> root_;
	std::shared_ptr<Node> supervisor_;
	std::shared_ptr<Node> doctor_;
	std::vector<std::shared_ptr<Node>> internCollection_;
}

- (void)setUp {
	srand((unsigned int)time(0));

	root_ = std::make_shared<Node>();
}

- (void)tearDown {
	// Empty
}

- (void)test_AddChildNode_Twice_ThatAlreadyHasParent {
	[self addSupervisor];
	[self addDoctorToSupervisor];
	supervisor_->addChildNode(doctor_);
	XCTAssertEqual(supervisor_->getNumOfChildNodes(), 1);
}

- (void)test_AddRemove {
	[self addSupervisor];
	[self addDoctorToSupervisor];
	[self addInternCollectionToDoctor];

	/*!
	 *    ROOT (-1)
	 *    └── SUPERVISOR (0)
	 *         └── DOCTOR (0)
	 *              ├── INTERN A (0)
	 *              ├── INTERN B (1)
	 *              └── INTERN C (2)
	 */
	XCTAssertEqual(doctor_->getNumOfChildNodes(), 3);

	supervisor_->removeChildNode(doctor_);
	XCTAssertEqual(internCollection_[IDX_INTERN_B]->getNodeIdx().equals(NodeIdx({ NODEIDX_ROOT, IDX_INTERN_B })), true);

	root_->addChildNode(doctor_);
	XCTAssertEqual(internCollection_[IDX_INTERN_B]->getNodeIdx().equals(NodeIdx({ NODEIDX_ROOT, 1, IDX_INTERN_B })), true);
}

- (void)test_GetChildNode {
	[self addSupervisor];
	[self addDoctorToSupervisor];
	[self addInternCollectionToDoctor];

	auto internIdx = NodeIdx({ NODEIDX_ROOT, 0, 0, IDX_INTERN_C });
	auto intern = doctor_->getChildNode(internIdx);
	XCTAssert(internIdx.equals(intern->getNodeIdx()));
}

- (void)test_GetChildNode_NonExistent {
	[self addSupervisor];
	[self addDoctorToSupervisor];
	[self addInternCollectionToDoctor];
	
	auto internIdx = NodeIdx({ NODEIDX_ROOT, 0, 0, IDX_INTERN_B });
	auto intern = doctor_->getChildNode(internIdx);
	XCTAssert(internIdx.equals(intern->getNodeIdx()));
}

- (void)addSupervisor {
	supervisor_ = std::make_shared<Node>();
	root_->addChildNode(supervisor_);
}

- (void)addDoctorToSupervisor {
	doctor_ = std::make_shared<Node>();
	supervisor_->addChildNode(doctor_);
}

- (void)addInternCollectionToDoctor {
	for (auto name : InternNameList)
		internCollection_.push_back([self addInternToDoctor]);
}

- (std::shared_ptr<Node>)addInternToDoctor {
	std::shared_ptr<Node> intern = std::make_shared<Node>();
	doctor_->addChildNode(intern);
	return intern;
}

@end
