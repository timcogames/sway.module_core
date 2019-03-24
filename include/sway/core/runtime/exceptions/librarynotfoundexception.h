#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_H
#define SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_H

#include <sway/core/runtime/exception.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class LibraryNotFoundException : public Exception {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] libName
	 *    Имя библиотеки.
	 * 
	 * \param[in] dlerror
	 *    Текст, подробно описывающий ошибку.
	 */
	LibraryNotFoundException(const std::string & libName, const std::string & dlerror = "")
		: Exception([libName]() -> std::string {
			return (boost::format("Cannot load library: %s") % libName).str();
		} ())
		, _libName(libName)
		, _dlerror(dlerror) {
		// Empty
	}

	/*!
	 * \brief
	 *    Возвращает имя библиотеки.
	 */
	std::string getLibName() const {
		return _libName;
	}

	/*!
	 * \brief
	 *    Возвращает текст, подробно описывающий ошибку.
	 */
	std::string getDlerror() const {
		return _dlerror;
	}

private:
	std::string _libName; /*!< Имя библиотеки. */
	std::string _dlerror; /*!< Текст, подробно описывающий ошибку. */
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_H
