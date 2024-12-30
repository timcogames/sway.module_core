#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP

#include <sway/core/runtime/exception.hpp>

namespace sway::core {

class LibraryNotFoundException : public Exception {
public:
  LibraryNotFoundException(const std::string &libName, const std::string &dlerror = "")
      : Exception([libName]() -> std::string { return format("Cannot load library: %s", libName.c_str()); }())
      , libname_(libName)
      , dlError_(dlerror) {}

  [[nodiscard]] auto getLibName() const -> std::string { return libname_; }

  [[nodiscard]] auto getDlerror() const -> std::string { return dlError_; }

private:
  std::string libname_;  //!< \~english Library name. \~russian Имя библиотеки.
  std::string dlError_;  //!< \~english Error text. \~russian Текст, подробно описывающий ошибку.
};

}  // namespace sway::core

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP
