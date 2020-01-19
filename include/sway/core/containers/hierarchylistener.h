#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H

#include <sway/core/containers/hierarchynodeidx.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class HierarchyListener {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~HierarchyListener() = default;

#pragma endregion // Constructor / Destructor

	virtual void onNodeAdded(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}

	virtual void onNodeRemoved(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}

	virtual void onNodeUpdated(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYLISTENER_H
