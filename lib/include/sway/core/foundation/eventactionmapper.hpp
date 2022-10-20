#ifndef SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP
#define SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP

#include <sway/core/foundation/eventapplier.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/namespacemacros.hpp>

#include <iostream>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class ActionMapper {
public:
  PURE_VIRTUAL(void initialize(EventApplier *applier));
};

template <typename... TEventArgs>
class EventActionMapper : public ActionMapper, public TEventArgs... {
public:
  EventActionMapper() = default;

  ~EventActionMapper() = default;

  MTHD_OVERRIDE(void initialize(EventApplier *applier)) {
    auto self = this;
    doForEachEvent(self, [&](auto *base) {
      using ConcreteEventType_t = typename std::decay_t<decltype(*base)>::EventType_t;
      applier->registerEvent<ConcreteEventType_t>(self);
    });
  }

private:
  template <typename TVisitor>
  void doForEachEvent(EventActionMapper *self, TVisitor &&visitor) {
    (void(visitor(static_cast<TEventArgs *>(self))), ...);
  }
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
