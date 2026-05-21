#ifndef SWAY_CORE_EVENTS_V2_EVENTLISTENER_HPP
#define SWAY_CORE_EVENTS_V2_EVENTLISTENER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/v2/_typedefs.hpp>

namespace sway::core::v2 {

class EventListener {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EventListener() = default;

  virtual ~EventListener() = default;

  /** @} */
#pragma endregion

  virtual void handleEvent(EventUniquePtr_t &&event) = 0;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTLISTENER_HPP
