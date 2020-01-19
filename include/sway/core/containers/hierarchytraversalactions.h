#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSALACTIONS_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSALACTIONS_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

enum class HierarchyTraversalActions : u32_t {
	Continue, /*!< Продолжать обходить. */
	Prune, /*!< Не навещай дочерние узлы. */
	Abort /*!< Прервать обход. */
};

typedef HierarchyTraversalActions TraversalAction_t;

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYTRAVERSALACTIONS_H
