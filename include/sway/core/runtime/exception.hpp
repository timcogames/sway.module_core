#ifndef _SWAY_CORE_RUNTIME_EXCEPTION_H
#define _SWAY_CORE_RUNTIME_EXCEPTION_H

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <exception> // std::exception
#include <string> // std::string

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)

class Exception : public std::exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] message
	 *    Сообщение об ошибке, объясняющее причину исключения.
	 */
	Exception(const std::string & message)
		: _message(message) {
		// Empty
	}

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Exception() throw() = default;

	/*!
	 * \brief
	 *    Возвращает строку-пояснение.
	 */
	virtual lpcstr_t what() const throw() {
		return _message.c_str();
	}

private:
	std::string _message; /*!< Сообщение об ошибке. */
};

NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_RUNTIME_EXCEPTION_H
