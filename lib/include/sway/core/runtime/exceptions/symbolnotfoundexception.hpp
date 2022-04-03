#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP

#include <sway/core/misc/format.hpp>
#include <sway/core/runtime/exception.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class SymbolNotFoundException : public Exception {
public:
  SymbolNotFoundException(const std::string &symbolName, const std::string &dlerror = "")
      : Exception(
            [symbolName]() -> std::string { return misc::format("Cannot find symbol: %s", symbolName.c_str()); }())
      , symbolName_(symbolName)
      , dlError_(dlerror) {}

  std::string getSymbolName() const { return symbolName_; }

  std::string getDlerror() const { return dlError_; }

private:
  std::string symbolName_; /*!< Имя символа. */
  std::string dlError_; /*!< Текст, подробно описывающий ошибку. */
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
