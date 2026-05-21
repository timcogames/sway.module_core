#ifndef SWAY_CORE_EVENTS_V2_CALLBACK_HPP
#define SWAY_CORE_EVENTS_V2_CALLBACK_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/v2/_typedefs.hpp>
#include <sway/core/events/v2/rawable.hpp>

namespace sway::core::v2 {

template <typename RETURN, typename PARAM>
class Callback {
public:
#pragma region "Static methods"

  static void call(DelegatePtr_t<RETURN, PARAM> delegate, PARAM param) {
    if (delegate != nullptr) {
      (*delegate)(param);
    }
  }

#pragma endregion

#pragma region "Pure virtual methods"

  virtual RETURN invoke(PARAM param) = 0;

#pragma endregion
};

template <typename RETURN, typename PARAM, typename TYPE, typename METHOD>
class MethodCallback : public Callback<RETURN, PARAM>, public Rawable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  MethodCallback(void *object, METHOD method)
      : Rawable(object)
      , method_(method) {}

  /** @} */
#pragma endregion

  virtual RETURN invoke(PARAM param) { return (getRawAs<TYPE>()->*method_)(param); }

private:
  METHOD method_;
};

template <typename RETURN, typename PARAM>
class StaticCallback : public Callback<RETURN, PARAM> {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  StaticCallback(RETURN (*func)(PARAM))
      : func_(func) {}

  /** @} */
#pragma endregion

  virtual RETURN invoke(PARAM param) { return (*func_)(param); }

private:
  RETURN (*func_)(PARAM);
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_CALLBACK_HPP
