#ifndef SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP
#define SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventlistenerlist.hpp>

namespace sway::core::v2 {

class EventService {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EventService() {}

  ~EventService() = default;

  /** @} */
#pragma endregion

  void fireEvent(Event event) {}

private:
  EventListenerList listeners_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP
