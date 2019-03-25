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
	 *    Конструктор класса по умолчанию.
	 * 
	 * \sa
	 *    TFunction(decltype (nullptr))
	 *    TFunction(ProcAddress_t ptr)
	 */
	TFunction();

	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \sa
	 *    TFunction()
	 *    TFunction(ProcAddress_t ptr)
	 */
	TFunction(decltype (nullptr));

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
	TFunction(ProcAddress_t ptr);

	/*!
	 * \brief
	 *    Определяет, сохранен ли объект вызываемой функции.
	 */
	operator bool() const;

	bool operator== (decltype (nullptr)) const;

	bool operator!= (decltype (nullptr)) const;

	bool operator!= (const TFunction<ReturnType(Arguments...)> & function) const;

	/*!
	 * \brief
	 *    Выполняет вызов функции.
	 * 
	 * \param[in] args
	 *     Аргументы функции.
	 */
	ReturnType operator() (Arguments... args);

	/*!
	 * \brief
	 *    Выполняет вызов функции.
	 * 
	 * \param[in] args
	 *     Аргументы функции.
	 */
	ReturnType call(Arguments... args);

protected:
	ProcAddress_t _invoker; /*!< Указатель на функции. */
};

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/binding/function.inl>

#endif // SWAY_CORE_BINDING_FUNCTION_H
