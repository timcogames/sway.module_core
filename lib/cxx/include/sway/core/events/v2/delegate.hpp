#ifndef SWAY_CORE_EVENTS_V2_DELEGATE_HPP
#define SWAY_CORE_EVENTS_V2_DELEGATE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/v2/callback.hpp>

namespace sway::core::v2 {

template <typename RETURN, typename PARAM>
class Delegate {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Delegate(RETURN (*func)(PARAM))
      : callback_(new StaticCallback<RETURN, PARAM>(func)) {}

  template <typename TYPE, typename METHOD>
  Delegate(TYPE *object, METHOD method)
      : callback_(new MethodCallback<RETURN, PARAM, TYPE, METHOD>(object, method)) {}

  ~Delegate() { delete callback_; }

  /** @} */
#pragma endregion

  RETURN operator()(PARAM param) { return callback_->invoke(param); }

private:
  Callback<RETURN, PARAM> *callback_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_DELEGATE_HPP
