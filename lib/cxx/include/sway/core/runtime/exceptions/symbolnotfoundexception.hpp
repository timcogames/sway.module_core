#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP

#include <sway/core/misc/format.hpp>
#include <sway/core/runtime/exception.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(runtime)
NS_BEGIN(exceptions)

class SymbolNotFoundException : public Exception {
public:
  SymbolNotFoundException(const std::string &symbolName, const std::string &dlerror = "")
      : Exception(
            [symbolName]() -> std::string { return misc::format("Cannot find symbol: %s", symbolName.c_str()); }())
      , symbolName_(symbolName)
      , dlError_(dlerror) {}

  [[nodiscard]]
  auto getSymbolName() const -> std::string {
    return symbolName_;
  }

  [[nodiscard]]
  auto getDlerror() const -> std::string {
    return dlError_;
  }

private:
  std::string symbolName_;  // Имя символа.
  std::string dlError_;  // Текст, подробно описывающий ошибку.
};

NS_END()  // namespace exceptions
NS_END()  // namespace runtime
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_SYMBOLNOTFOUNDEXCEPTION_HPP
