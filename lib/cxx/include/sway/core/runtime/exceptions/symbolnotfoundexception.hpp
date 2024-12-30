#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP

#include <sway/core/misc/format.hpp>
#include <sway/core/runtime/exception.hpp>

namespace sway::core {

class SymbolNotFoundException : public Exception {
public:
  SymbolNotFoundException(const std::string &symbolName, const std::string &dlerror = "")
      : Exception([symbolName]() -> std::string { return format("Cannot find symbol: %s", symbolName.c_str()); }())
      , symbolName_(symbolName)
      , dlError_(dlerror) {}

  [[nodiscard]] auto getSymbolName() const -> std::string { return symbolName_; }

  [[nodiscard]] auto getDlerror() const -> std::string { return dlError_; }

private:
  std::string symbolName_;  //!< \~english Symbol name. \~russian Имя символа.
  std::string dlError_;  //!< \~english Error text. \~russian Текст, подробно описывающий ошибку.
};

}  // namespace sway::core

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
