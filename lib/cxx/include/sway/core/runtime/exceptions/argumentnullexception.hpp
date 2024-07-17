#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP

#include <sway/core/misc/format.hpp>
#include <sway/core/runtime/exception.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)
NAMESPACE_BEGIN(exceptions)

class ArgumentNullException : public Exception {
public:
  ArgumentNullException(const std::string &argumentName, std::string message = std::string())
      : Exception([argumentName, message]() -> std::string {
        return misc::format(
            message.empty() ? "Value cannot be null. Parameter name: %s" : message.c_str(), argumentName.c_str());
      }())
      , argname_(argumentName) {}

  [[nodiscard]]
  auto getArgumentName() const -> std::string {
    return argname_;
  }

private:
  std::string argname_;
};

NAMESPACE_END(exceptions)
NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP
