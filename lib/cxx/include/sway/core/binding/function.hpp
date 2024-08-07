#ifndef SWAY_CORE_BINDING_FUNCTION_HPP
#define SWAY_CORE_BINDING_FUNCTION_HPP

#include <sway/core/binding/procaddress.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <utility>  // std::forward

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(binding)

template <typename>
class TFunction;

template <typename RETURN_TYPE, typename... ARGS>
class TFunction<RETURN_TYPE(ARGS...)> {
public:
  TFunction()
      : invoker_(nullptr) {}

  TFunction(decltype(nullptr)) {}

  TFunction(ProcAddress_t ptr)
      : invoker_(ptr) {}

  explicit operator bool() const { return invoker_ != nullptr; }

  auto operator==(decltype(nullptr)) const -> bool { return (invoker_ == nullptr); }

  auto operator!=(decltype(nullptr)) const -> bool { return (invoker_ != nullptr); }

  auto operator!=(const TFunction<RETURN_TYPE(ARGS...)> &func) const -> bool { return invoker_ != func.invoker_; }

  auto operator()(ARGS... args) -> RETURN_TYPE { return call(args...); }

  auto call(ARGS... args) -> RETURN_TYPE {
    return (*reinterpret_cast<RETURN_TYPE (*)(ARGS...)>(invoker_))(std::forward<ARGS>(args)...);
  }

protected:
  ProcAddress_t invoker_;  // Указатель на функции.
};

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_BINDING_FUNCTION_HPP
