#import <XCTest/XCTest.h>
#import <sway/core/container/node.hpp>
#import <sstream>

#define NODE_IDX_SUPERVISOR (0)
#define NODE_IDX_WORKER (1)

using namespace sway::core::container;

@interface xctestcase_commons_NodeIdx : XCTestCase
@end

@implementation xctestcase_commons_NodeIdx {
	NodeIdx root_;
	NodeIdx supervisor_;
	NodeIdx worker_;
}

- (void)setUp {
	root_ = NodeIdx(NODEIDX_CHAIN_INITIALROOT);
	supervisor_ = NodeIdx(root_, NODE_IDX_SUPERVISOR);
	worker_ = NodeIdx(supervisor_, NODE_IDX_WORKER);

	/*!
	 *    ROOT (-1)
	 *    └── SUPERVISOR (0)
	 *         └── WORKER (1)
	 */
}

- (void)test_Equality {
	XCTAssert(worker_.equals(NodeIdx({ NODEIDX_ROOT, NODE_IDX_SUPERVISOR, NODE_IDX_WORKER })));
}

- (void)test_ToString {
	std::stringstream stream;
	stream << "[" << NODEIDX_ROOT << ", " << NODE_IDX_SUPERVISOR << ", " << NODE_IDX_WORKER << "]";
	XCTAssertEqual(worker_.toStr() == stream.str(), true);
}

@end
