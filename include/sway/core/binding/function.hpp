#ifndef _SWAY_CORE_BINDING_FUNCTION_HPP
#define _SWAY_CORE_BINDING_FUNCTION_HPP

#include <sway/core/binding/procaddress.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <utility> // std::forward

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
	 *    Конструктор класса по умолчанию.
	 * 
	 * \sa
	 *    TFunction(decltype (nullptr))
	 *    TFunction(ProcAddress_t ptr)
	 */
	TFunction() : _invoker(nullptr) { }

	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \sa
	 *    TFunction()
	 *    TFunction(ProcAddress_t ptr)
	 */
	TFunction(decltype (nullptr)) { }

	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] ptr
	 *     Указатель на вызываемую функцию.
	 * 
	 * \sa
	 *    TFunction()
	 *    TFunction(decltype (nullptr))
	 */
	TFunction(ProcAddress_t ptr) : _invoker(ptr) { }

	/*!
	 * \brief
	 *    Определяет, сохранен ли объект вызываемой функции.
	 */
	operator bool() const {
		return _invoker != nullptr;
	}

	bool operator== (decltype (nullptr)) const {
		return (_invoker == nullptr);
	}

	bool operator!= (decltype (nullptr)) const {
		return (_invoker != nullptr);
	}

	bool operator!= (const TFunction<ReturnType(Arguments...)> & function) const {
		return _invoker != function._invoker;
	}

	/*!
	 * \brief
	 *    Выполняет вызов функции.
	 * 
	 * \param[in] args
	 *     Аргументы функции.
	 */
	ReturnType operator() (Arguments... args) {
		return call(args...);
	}

	/*!
	 * \brief
	 *    Выполняет вызов функции.
	 * 
	 * \param[in] args
	 *     Аргументы функции.
	 */
	ReturnType call(Arguments... args) {
		return (*reinterpret_cast<ReturnType (*)(Arguments...)>(_invoker))(std::forward<Arguments>(args)...);
	}

protected:
	ProcAddress_t _invoker; /*!< Указатель на функции. */
};

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_BINDING_FUNCTION_HPP
