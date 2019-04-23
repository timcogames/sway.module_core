#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_H
#define SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_H

#include <sway/core/runtime/exception.h>
#include <sway/core/misc/format.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class ArgumentNullException : public Exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] argumentName
	 *    Имя аргумента.
	 * 
	 * \param[in] message
	 *    Сообщение об ошибке.
	 */
	ArgumentNullException(const std::string & argumentName, std::string message = std::string())
		: Exception([argumentName, message]() -> std::string {
			return misc::format(message.empty()
				? "Value cannot be null. Parameter name: %s" : message.c_str(), argumentName.c_str());
		} ())
		, _argumentName(argumentName) {
		// Empty
	}

	/*!
	 * \brief
	 *    Возвращает имя аргумента.
	 */
	std::string getArgumentName() const {
		return _argumentName;
	}

private:
	std::string _argumentName;
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_H
