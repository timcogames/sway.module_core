#ifndef SWAY_CORE_EVENTS_V2_TYPEDEFS_HPP
#define SWAY_CORE_EVENTS_V2_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core::v2 {

/**
 * @defgroup event The Event typedefs
 * @ingroup events_v2
 * @brief \~english Definition of event types. \~russian Определение типов событий.
 */
class Event;

/**
 * @defgroup event_target The EventTaget typedefs
 * @ingroup events_v2
 * @brief \~english Definition of event target types. \~russian Определение типов целевых объектов событий.
 */
class EventTarget;

namespace typedefs {

/**
 * @ingroup events_v2 event
 * @brief \~english Class Event in @link events_v2 the events_v2 group@endlink. \~russian Класс Event в @link events_v2
 * the events_v2 group@endlink.
 */
using EventPtr_t = Event *;

/**
 * @ingroup events_v2 event_target
 * @brief \~english Class EventTarget in @link events_v2 the events_v2 group@endlink. \~russian Класс EventTarget в
 * @link events_v2 the events_v2 group@endlink.
 */
using EventTargetPtr_t = EventTarget *;
}  // namespace typedefs

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_TYPEDEFS_HPP
