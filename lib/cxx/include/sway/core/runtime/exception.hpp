#ifndef SWAY_CORE_RUNTIME_EXCEPTION_HPP
#define SWAY_CORE_RUNTIME_EXCEPTION_HPP

#include <sway/_stdafx.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Exception : public std::exception {
public:
  Exception(const std::string &message)
      : message_(message) {}

  virtual ~Exception() throw() = default;

  [[nodiscard]] virtual auto what() const throw() -> lpcstr_t { return message_.c_str(); }

private:
  std::string message_;  //!< \~english Error message. \~russian Сообщение об ошибке.
};

}  // namespace sway::core

#endif  // SWAY_CORE_RUNTIME_EXCEPTION_HPP
