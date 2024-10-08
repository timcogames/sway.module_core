#ifndef SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP

#include <sway/core/misc/format.hpp>
#include <sway/core/runtime/exception.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(runtime)
NS_BEGIN(exceptions)

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

NS_END()  // namespace exceptions
NS_END()  // namespace runtime
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_RUNTIME_EXCEPTIONS_ARGUMENTNULLEXCEPTION_HPP
