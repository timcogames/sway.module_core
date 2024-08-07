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
#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void registerEvents(EventApplier *applier));

#pragma endregion
};

template <typename... ARGS>
class EventActionMapper : public ActionMapper, public ARGS... {
public:
  virtual ~EventActionMapper() = default;

#pragma region "Override ActionMapper methods"

  MTHD_OVERRIDE(void registerEvents(EventApplier *applier)) {
    auto self = this;
    doForEachEvent(self, [&](auto *base) {
      using ConcreteEventType_t = typename std::decay_t<decltype(*base)>::EventType_t;
      applier->registerEvent<ConcreteEventType_t>(self);
    });
  }

#pragma endregion

private:
  template <typename VISITOR>
  void doForEachEvent(EventActionMapper *self, VISITOR &&visitor) {
    (void(visitor(static_cast<ARGS *>(self))), ...);
  }
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP
