#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYNODELISTENER_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYNODELISTENER_H

#include <sway/core/containers/hierarchynodeidx.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

enum HierarchyNodeListenerFlags : u32_t {
	Added,
	Removed,
	Updated
};

typedef HierarchyNodeListenerFlags NodeListenerFlag_t;

class HierarchyNodeListener {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~HierarchyNodeListener() = default;

#pragma endregion

	virtual void onNodeAdded(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}

	virtual void onNodeRemoved(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}

	virtual void onNodeChanged(const HierarchyNodeIdx & nodeIdx) {
		// Empty
	}
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYNODELISTENER_H
