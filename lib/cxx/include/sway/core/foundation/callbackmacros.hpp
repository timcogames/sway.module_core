#ifndef SWAY_CORE_BINDING_CALLBACKMACROS_HPP
#define SWAY_CORE_BINDING_CALLBACKMACROS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

#define RUN_CALLBACK(FUNC, ARGS...) \
  [=]() {                           \
    if (FUNC == nullptr) {          \
      return;                       \
    }                               \
    FUNC(ARGS);                     \
  }()

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_BINDING_CALLBACKMACROS_HPP
