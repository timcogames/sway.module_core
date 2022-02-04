#ifndef _SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define _SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(intrusive)

/*!
 * \brief
 *    Перечисление приоритетов.
 */
enum Priorities {
	kPriority_VeryLow = 0, /*!< Очень низкий приоритет. */
	kPriority_Low = 1, /*!< Низкий приоритет. */
	kPriority_Normal = 2, /*!< Средний приоритет. */
	kPriority_High = 3, /*!< Высокий приоритет. */
	kPriority_VeryHigh = 4 /*!< Очень высокий приоритет. */
};

NAMESPACE_END(intrusive)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
