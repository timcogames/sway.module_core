#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/foundation/object.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

void AEventHandler::registerEmsClass() {
#ifdef _EMSCRIPTEN
	emscripten::class_<AEventHandler>("AEventHandler")
		.allow_subclass<AEventHandlerWrapper>("AEventHandlerWrapper", emscripten::constructor<Object *>())
		.function("invoke", &AEventHandler::invoke, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
		.function("getSender", &AEventHandler::getSender, emscripten::allow_raw_pointers())
		.function("setSender", &AEventHandler::setSender, emscripten::allow_raw_pointers())
		.function("getReceiver", &AEventHandler::getReceiver, emscripten::allow_raw_pointers());
#endif
}

AEventHandler::AEventHandler(Object * receiver)
	: receiver_(receiver) { }

Object * AEventHandler::getSender() const {
	return sender_;
}

void AEventHandler::setSender(Object * sender) {
	sender_ = sender;
}

Object * AEventHandler::getReceiver() const {
	return receiver_;
}

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
