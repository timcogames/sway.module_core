#ifndef _SWAY_CORE_UTILS_TRAVERSER_HPP
#define _SWAY_CORE_UTILS_TRAVERSER_HPP

#include <sway/core/utils/traversalactions.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class IVisitable;
class ITraverser {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~ITraverser() = default;

#pragma endregion

#pragma region "Pure virtual methods"

	virtual TraversalAction visit(IVisitable * node) = 0;

#pragma endregion

};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_TRAVERSER_HPP
