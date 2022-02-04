#ifndef _SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
#define _SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP

#include <sway/core/runtime/exception.hpp>
#include <sway/core/misc/format.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class SymbolNotFoundException : public Exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] symbolName
	 *    Имя символа.
	 * 
	 * \param[in] dlerror
	 *    Текст, подробно описывающий ошибку.
	 */
	SymbolNotFoundException(const std::string & symbolName, const std::string & dlerror = "")
		: Exception([symbolName]() -> std::string {
			return misc::format("Cannot find symbol: %s", symbolName.c_str());
		} ())
		, _symbolName(symbolName)
		, _dlerror(dlerror) {
		// Empty
	}

	/*!
	 * \brief
	 *    Возвращает имя символа.
	 */
	std::string getSymbolName() const {
		return _symbolName;
	}

	/*!
	 * \brief
	 *    Возвращает текст, подробно описывающий ошибку.
	 */
	std::string getDlerror() const {
		return _dlerror;
	}

private:
	std::string _symbolName; /*!< Имя символа. */
	std::string _dlerror; /*!< Текст, подробно описывающий ошибку. */
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
