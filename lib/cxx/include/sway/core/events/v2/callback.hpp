#ifndef SWAY_CORE_EVENTS_V2_CALLBACK_HPP
#define SWAY_CORE_EVENTS_V2_CALLBACK_HPP

#include <sway/_stdafx.hpp>

#include <cassert>  // assert

namespace sway::core::v2 {

template <typename RETURN, typename PARAM>
class Callback {
public:
  virtual ~Callback() = default;

#pragma region "Pure virtual methods"

  virtual auto invoke(PARAM param) -> RETURN = 0;

#pragma endregion
};

template <typename RETURN, typename PARAM, typename TYPE>
class MethodCallback : public Callback<RETURN, PARAM> {
public:
  using MethodPtr_t = RETURN (TYPE::*)(PARAM);

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  MethodCallback(TYPE *object, MethodPtr_t method)
      : object_(object)
      , method_(method) {
    assert(object_ != nullptr);
  }

  /** @} */
#pragma endregion

  auto invoke(PARAM param) override -> RETURN { return (object_->*method_)(param); }

private:
  TYPE *object_;
  MethodPtr_t method_;
};

template <typename RETURN, typename PARAM>
class StaticCallback : public Callback<RETURN, PARAM> {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  explicit StaticCallback(RETURN (*func)(PARAM))
      : func_(func) {
    assert(func_ != nullptr);
  }

  /** @} */
#pragma endregion

  auto invoke(PARAM param) -> RETURN override { return func_(param); }

private:
  RETURN (*func_)(PARAM);
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_CALLBACK_HPP
