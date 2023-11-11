#ifndef SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(intrusive)

/**
 * @brief Перечисление приоритетов.
 */
enum Priorities {
  Priority_VeryLow = 0,  // Очень низкий приоритет.
  Priority_Low = 1,  // Низкий приоритет.
  Priority_Normal = 2,  // Средний приоритет.
  Priority_High = 3,  // Высокий приоритет.
  Priority_VeryHigh = 4  // Очень высокий приоритет.
};

NAMESPACE_END(intrusive)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
