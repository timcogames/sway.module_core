#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

// class ThingyContext : public core::foundation::Context {
// public:
// 	ThingyContext() = default;
// 	virtual ~ThingyContext() = default;
// };

// class ThingyObject : public core::foundation::Object {
// 	DECLARE_OBJECT(ThingyObject, core::foundation::Object)

// public:
// 	ThingyObject(core::foundation::Context * context) : core::foundation::Object(context) {
// 		// Empty
// 	}

// 	~ThingyObject() = default;
// };

// bool correctMessage(const core::runtime::exceptions::ArgumentNullException & exception) {
// 	BOOST_CHECK_EQUAL(exception.what(), "Value cannot be null. Parameter name: object");
// 	return true;
// }

// BOOST_FIXTURE_TEST_SUITE(ThingyContext_TestSuite, ThingyContext);

// BOOST_AUTO_TEST_CASE(ThingyContext_TestCase) {
// 	ThingyObject * object = new ThingyObject(this);

// 	BOOST_CHECK_EXCEPTION(registerObject(nullptr), core::runtime::exceptions::ArgumentNullException, correctMessage);
// 	BOOST_CHECK_NO_THROW(registerObject(object));
// 	BOOST_CHECK_EQUAL(getObjectCount(), 1);

// 	const std::string objectClassName = "ThingyObject";
// 	BOOST_CHECK_EQUAL(getObject(objectClassName)->getClassName(), objectClassName);

// 	unregisterObject(objectClassName);
// 	BOOST_CHECK_EQUAL(getObjectCount(), 0);

// 	SAFE_DELETE(object);
// }

//BOOST_AUTO_TEST_SUITE_END();
