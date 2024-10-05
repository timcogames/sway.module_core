#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP

#include <sway/core/runtime/exception.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(runtime)
NS_BEGIN(exceptions)

class LibraryNotFoundException : public Exception {
public:
  LibraryNotFoundException(const std::string &libName, const std::string &dlerror = "")
      : Exception([libName]() -> std::string { return misc::format("Cannot load library: %s", libName.c_str()); }())
      , libname_(libName)
      , dlError_(dlerror) {}

  [[nodiscard]]
  auto getLibName() const -> std::string {
    return libname_;
  }

  [[nodiscard]]
  auto getDlerror() const -> std::string {
    return dlError_;
  }

private:
  std::string libname_;  // Имя библиотеки.
  std::string dlError_;  // Текст, подробно описывающий ошибку.
};

NS_END()  // namespace exceptions
NS_END()  // namespace runtime
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_LIBRARYNOTFOUNDEXCEPTION_HPP
