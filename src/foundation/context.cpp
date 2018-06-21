#include <sway/core/foundation/context.h>
#include <sway/exceptions.h>
#include <exception> // std::exception

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

Context::Context() {
	// Empty
}

Context::~Context() {
	_objects.clear();
}

void Context::registerObject(Object * object) {
	if (!object)
		throw ArgumentNullException();

	_objects.insert(std::make_pair(object->getClassName(), object));
}

void Context::unregisterObject(const std::string & objectClassName) {
	ObjectMap_t::const_iterator iter = _objects.find(objectClassName);
	if (iter != _objects.end())
		_objects.erase(iter);
}

Object * Context::getObject(const std::string & objectClassName) const {
	ObjectMap_t::const_iterator iter = _objects.find(objectClassName);
	if (iter != _objects.end())
		return iter->second;

	return 0;
}

u32_t Context::getObjectCount() const {
	return _objects.size();
}

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
