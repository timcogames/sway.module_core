#ifndef _SWAY_CORE_UTILITIES_VISITOR_H
#define _SWAY_CORE_UTILITIES_VISITOR_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utilities)

class Visitor {
public:
	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Visitor() = default;
};

NAMESPACE_END(utilities)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILITIES_VISITOR_H
