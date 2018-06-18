#ifndef SWAY_CORE_EXCEPTION_H
#define SWAY_CORE_EXCEPTION_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string> // std::string
#include <exception> // std::exception

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

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
	 *    Деструктор класса.
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
	std::string _message; /*!< Сообщение об ошибке */
};

class ArgumentException : public Exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 */
	ArgumentException() : Exception("Invalid argument") {
		// Empty
	}

	/*!
	 * \brief
	 *   Конструктор класса.
	 * 
	 * \param[in] argName
	 *    Имя аргумента.
	 */
	ArgumentException(const std::string & argName) : Exception("Invalid argument: " + argName) {
		// Empty
	}
};

class NullArgumentException : public Exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 */
	NullArgumentException() : Exception("Null argument") {
		// Empty
	}

	/*!
	 * \brief
	 *   Конструктор класса.
	 * 
	 * \param[in] argName
	 *    Имя аргумента.
	 */
	NullArgumentException(const std::string & argName) : Exception("Null argument: " + argName) {
		// Empty
	}
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_EXCEPTION_H
