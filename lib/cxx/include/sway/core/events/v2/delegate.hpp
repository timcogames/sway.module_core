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
      : callback_(std::make_unique<StaticCallback<RETURN, PARAM>>(func)) {}

  template <typename TYPE>
  Delegate(TYPE *object, RETURN (TYPE::*method)(PARAM))
      : callback_(std::make_unique<MethodCallback<RETURN, PARAM, TYPE>>(object, method)) {}

  /** @} */
#pragma endregion

  auto operator()(PARAM param) const -> RETURN { return callback_->invoke(param); }

private:
  std::unique_ptr<Callback<RETURN, PARAM>> callback_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_DELEGATE_HPP
