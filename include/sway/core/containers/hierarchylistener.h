#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H

#include <sway/core/containers/hierarchynodeindex.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class HierarchyNode;
//typedef std::shared_ptr<HierarchyNode> HierarchyNodePtr_t;
typedef HierarchyNode * HierarchyNodePtr_t;

class HierarchyListener {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~HierarchyListener() = default;

#pragma endregion // Constructor / Destructor

	virtual void onNodeAdded(const HierarchyNodeIndex & nodeIndex) {
		// Empty
	}

	virtual void onNodeRemoved(HierarchyNodePtr_t parent, HierarchyNodePtr_t child) {
		// Empty
	}

	virtual void onNodeUpdated(const HierarchyNodeIndex & nodeIndex) {
		// Empty
	}
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H
