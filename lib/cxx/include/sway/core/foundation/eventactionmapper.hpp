#ifndef SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP
#define SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/eventapplier.hpp>
#include <sway/core/memory/safedeletemacros.hpp>

namespace sway::core {

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

#pragma region "Overridden ActionMapper methods"

  MTHD_VIRTUAL_OVERRIDE(void registerEvents(EventApplier *applier)) {
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

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENACTIONMAPPER_HPP
