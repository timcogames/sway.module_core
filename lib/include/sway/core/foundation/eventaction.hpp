#ifndef SWAY_CORE_FOUNDATION_EVENTACTION_HPP
#define SWAY_CORE_FOUNDATION_EVENTACTION_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

#include <map>
#include <memory>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template <typename TConcreteEvent>
class EventAction {
public:
  using EventType_t = TConcreteEvent;

  PURE_VIRTUAL(void apply(std::shared_ptr<TConcreteEvent> evt));
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
