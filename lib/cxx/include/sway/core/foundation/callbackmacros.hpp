#ifndef SWAY_CORE_BINDING_CALLBACKMACROS_HPP
#define SWAY_CORE_BINDING_CALLBACKMACROS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

#define RUN_CALLBACK(FUNC, ARGS...) \
  [=]() {                           \
    if (FUNC == nullptr) {          \
      return;                       \
    }                               \
    FUNC(ARGS);                     \
  }()

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_BINDING_CALLBACKMACROS_HPP
