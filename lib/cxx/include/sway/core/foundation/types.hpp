#ifndef SWAY_CORE_FOUNDATION_TYPES_HPP
#define SWAY_CORE_FOUNDATION_TYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context;
class Event;
class Eventable;
class EventHandler;

using ContextPtr_t = Context *;

using EventPtr_t = Event *;
using EventUniquePtr_t = std::unique_ptr<Event>;
using EventSharedPtr_t = std::shared_ptr<Event>;

using EventablePtr_t = Eventable *;

using EventHandlerPtr_t = EventHandler *;

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_TYPES_HPP
