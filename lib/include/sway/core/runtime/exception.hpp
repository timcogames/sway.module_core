#ifndef SWAY_CORE_RUNTIME_EXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTION_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <exception>  // std::exception
#include <string>  // std::string

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(runtime)

class Exception : public std::exception {
public:
  Exception(const std::string &message)
      : message_(message) {}

  virtual ~Exception() throw() = default;

  virtual lpcstr_t what() const throw() { return message_.c_str(); }

private:
  std::string message_;  // Сообщение об ошибке.
};

NAMESPACE_END(runtime)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_RUNTIME_EXCEPTION_HPP
