#ifndef _SWAY_CORE_UTILITIES_VISITABLE_H
#define _SWAY_CORE_UTILITIES_VISITABLE_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utilities)

class Visitor;

class IVisitable {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IVisitable() = default;

#pragma endregion // Constructor / Destructor

#pragma region "Pure virtual methods"

	virtual void accept(Visitor * visitor) = 0;

#pragma endregion // Pure virtual methods
};

NAMESPACE_END(utilities)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILITIES_VISITABLE_H
