#ifndef SWAY_CORE_BINDING_FUNCTION_H
#define SWAY_CORE_BINDING_FUNCTION_H

#include <sway/core/binding/procaddress.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(binding)

template<typename>
class TFunction;

template<typename ReturnType, typename... Arguments>
class TFunction<ReturnType (Arguments...)> {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 */
	TFunction(ProcAddress_t ptr);

	inline ReturnType operator()(Arguments... args);

	inline ReturnType call(Arguments... args);

private:
	ProcAddress_t _address;
};

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/binding/function.inl>

#endif // SWAY_CORE_BINDING_FUNCTION_H
