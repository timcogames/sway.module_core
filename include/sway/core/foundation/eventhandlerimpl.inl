#include <sway/core/foundation/eventhandlerimpl.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template<class TYPE>
TEventHandlerImpl<TYPE>::TEventHandlerImpl(TYPE * receiver, HandlerFunction_t function)
	: AEventHandler(receiver)
	, function_(std::move(function)) {
	// Empty
}

template<class TYPE>
void TEventHandlerImpl<TYPE>::invoke(IEvent * event) {
	TYPE * receiver = static_cast<TYPE *>(receiver_);
	(receiver->*function_)(event);
}

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
