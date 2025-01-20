#ifndef SWAY_CORE_EVENTS_V2_EVENTHANDLER_HPP
#define SWAY_CORE_EVENTS_V2_EVENTHANDLER_HPP

#include <sway/core/events/v2/_typedefs.hpp>
#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventcontext.hpp>

namespace sway::core::v2 {

/**
 * @brief \~english Represents a handler for an event. \~russian Представляет обработчик событий.
 */
class EventHandler {
public:
  virtual ~EventHandler();

  virtual void operator()(EventContext &context, Event &event) = 0;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTHANDLER_HPP
