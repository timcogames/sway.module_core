#ifndef _SWAY_CORE_CONTAINERS_TREELISTENER_H
#define _SWAY_CORE_CONTAINERS_TREELISTENER_H

#include <sway/core/containers/treenodeindex.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class TreeNodeBase;
//typedef std::shared_ptr<TreeNodeBase> TreeNodePtr_t;
typedef TreeNodeBase * TreeNodePtr_t;

class TreeListener {
public:
	virtual ~TreeListener() = default;

	virtual void onNodeUpdated(TreeNodePtr_t child) {
		// Empty
	}

	virtual void onNodeAdded(const TreeNodeIndex & nodeIndex) {
		// Empty
	}

	virtual void onNodeRemoved(TreeNodePtr_t parent, TreeNodePtr_t child) {
		// Empty
	}
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_TREELISTENER_H
