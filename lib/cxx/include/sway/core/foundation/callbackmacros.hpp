#ifndef SWAY_CORE_BINDING_CALLBACKMACROS_HPP
#define SWAY_CORE_BINDING_CALLBACKMACROS_HPP

namespace sway::core {

#define RUN_CALLBACK(FUNC, ARGS...) \
  [=]() {                           \
    if (FUNC == nullptr) {          \
      return;                       \
    }                               \
    FUNC(ARGS);                     \
  }()

}  // namespace sway::core

#endif  // SWAY_CORE_BINDING_CALLBACKMACROS_HPP
