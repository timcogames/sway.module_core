#ifndef SWAY_CORE_EVENTS_V2_EVENTTARGET_HPP
#define SWAY_CORE_EVENTS_V2_EVENTTARGET_HPP

#include <sway/_stdafx.hpp>

namespace sway::core::v2 {

/**
 * @brief \~english Base class for all objects that can generate events. \~russian Базовый класс для всех объектов,
 * которые могут генерировать события.
 */
class EventTarget {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EventTarget() {}

  ~EventTarget() = default;

  /** @} */
#pragma endregion
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTTARGET_HPP
