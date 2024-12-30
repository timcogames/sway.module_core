#ifndef SWAY_CORE_EVENTS_TYPEDEFS_HPP
#define SWAY_CORE_EVENTS_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

class Event;
namespace EventTypedefs {
using Ptr_t = Event *;
using UniquePtr_t = std::unique_ptr<Event>;
using SharedPtr_t = std::shared_ptr<Event>;
using QueueUniquePtr_t = std::queue<UniquePtr_t>;
}  // namespace EventTypedefs

class EventHandler;
namespace EventHandlerTypedefs {
using Ptr_t = EventHandler *;
using Container_t = std::vector<Ptr_t>;
}  // namespace EventHandlerTypedefs

class EventBus;
namespace EventBusTypedefs {
using Ptr_t = EventBus *;
using SharedPtr_t = std::shared_ptr<EventBus>;
}  // namespace EventBusTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_TYPEDEFS_HPP
