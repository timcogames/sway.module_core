#ifndef SWAY_CORE_RUNTIME_EXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTION_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <exception>  // std::exception
#include <string>  // std::string

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(runtime)

class Exception : public std::exception {
public:
  Exception(const std::string &message)
      : message_(message) {}

  virtual ~Exception() throw() = default;

  [[nodiscard]]
  virtual auto what() const throw() -> lpcstr_t {
    return message_.c_str();
  }

private:
  std::string message_;  // Сообщение об ошибке.
};

NS_END()  // namespace runtime
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_RUNTIME_EXCEPTION_HPP
