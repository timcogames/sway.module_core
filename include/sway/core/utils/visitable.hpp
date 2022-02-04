#ifndef _SWAY_CORE_UTILS_VISITABLE_H
#define _SWAY_CORE_UTILS_VISITABLE_H

#include <sway/core/utils/traversalactions.h>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class ITraverser;
class IVisitable {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IVisitable() = default;

#pragma endregion

#pragma region "Pure virtual methods"

	virtual TraversalAction traverse(ITraverser * traverser) = 0;

#pragma endregion
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_VISITABLE_H
