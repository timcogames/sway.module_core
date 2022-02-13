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

template <typename ReturnType, typename... Arguments>
class TFunction<ReturnType(Arguments...)> {
  public:
    TFunction()
        : invoker_(nullptr) {}

    TFunction(decltype(nullptr)) {}

    TFunction(ProcAddress_t ptr)
        : invoker_(ptr) {}

    explicit operator bool() const { return invoker_ != nullptr; }

    bool operator==(decltype(nullptr)) const { return (invoker_ == nullptr); }

    bool operator!=(decltype(nullptr)) const { return (invoker_ != nullptr); }

    bool operator!=(const TFunction<ReturnType(Arguments...)> &function) const { return invoker_ != function.invoker_; }

    ReturnType operator()(Arguments... args) { return call(args...); }

    ReturnType call(Arguments... args) {
        return (*reinterpret_cast<ReturnType (*)(Arguments...)>(invoker_))(std::forward<Arguments>(args)...);
    }

  protected:
    ProcAddress_t invoker_; /*!< Указатель на функции. */
};

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
