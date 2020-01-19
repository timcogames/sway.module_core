#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSER_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSER_H

#include <sway/core/containers/hierarchytraversalactions.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class HierarchyNode;
class IHierarchyTraverser {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IHierarchyTraverser() = default;

#pragma endregion

	virtual TraversalAction_t visit(HierarchyNode * node) = 0;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSER_H
