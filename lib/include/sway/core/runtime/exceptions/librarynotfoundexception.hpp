#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP

#include <sway/core/runtime/exception.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class LibraryNotFoundException : public Exception {
public:
  LibraryNotFoundException(const std::string &libName, const std::string &dlerror = "")
      : Exception([libName]() -> std::string { return misc::format("Cannot load library: %s", libName.c_str()); }())
      , libname_(libName)
      , dlError_(dlerror) {}

  auto getLibName() const -> std::string { return libname_; }

  auto getDlerror() const -> std::string { return dlError_; }

private:
  std::string libname_; /*!< Имя библиотеки. */
  std::string dlError_; /*!< Текст, подробно описывающий ошибку. */
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
