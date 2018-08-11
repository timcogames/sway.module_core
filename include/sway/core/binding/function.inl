#include <sway/core/binding/function.h>
#include <utility> // std::forward

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(binding)

template <typename ReturnType, typename... Arguments>
TFunction<ReturnType (Arguments...)>::TFunction(ProcAddress_t ptr)
	: _address(ptr) {
	// Empty
}

template <typename ReturnType, typename... Arguments>
ReturnType TFunction<ReturnType (Arguments...)>::operator()(Arguments... args) {
	return call(args...);
}

template <typename ReturnType, typename... Arguments>
ReturnType TFunction<ReturnType (Arguments...)>::call(Arguments... args) {
	return (*reinterpret_cast<ReturnType (*)(Arguments...)>(_address))(std::forward<Arguments>(args)...);
}

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)
