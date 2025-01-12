#ifndef SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP
#define SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP

#include <sway/_stdafx.hpp>

namespace sway::core::v2 {

/**
 * @brief \~english Represents the context in which the event occurred. \~russian Представляет контекст, в котором
 *   произошло событие.
 */
class EventContext {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EventContext() {}

  ~EventContext() = default;

  /** @} */
#pragma endregion
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP
