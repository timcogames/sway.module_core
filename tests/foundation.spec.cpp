#include <boost/test/unit_test.hpp>
#include <sway/core.h>

using namespace sway;

class ThingyContext : public core::foundation::Context {
  public:
	ThingyContext() = default;
	virtual ~ThingyContext() = default;
};

class ThingyObject : public core::foundation::Object {
	DECLARE_OBJECT(ThingyObject, core::foundation::Object)

  public:
	ThingyObject(core::foundation::Context * context) : core::foundation::Object(context) {
		// Empty
	}
	
	~ThingyObject() = default;
};

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_case) {
	ThingyContext * context = new ThingyContext();
	ThingyObject * object = new ThingyObject(context);

	context->registerObject(object);
	BOOST_CHECK_EQUAL(context->getObjectCount(), 1);

	const std::string objectClassName = "ThingyObject";
	BOOST_CHECK_EQUAL(context->getObject(objectClassName)->getClassName(), objectClassName);

	context->unregisterObject(objectClassName);
	BOOST_CHECK_EQUAL(context->getObjectCount(), 0);

	SAFE_DELETE(object);
	SAFE_DELETE(context);
}

BOOST_AUTO_TEST_SUITE_END()
