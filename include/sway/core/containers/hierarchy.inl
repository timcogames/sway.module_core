#include <sway/core/containers/hierarchy.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

template<typename TYPE = HierarchyNode>
TYPE * Hierarchy::findNode(const HierarchyNodeIdx & nodeIdx) {
	HierarchyNode * retrieved = _root;
	for (int i = 1/* пропускаем корневой индекс */; i < nodeIdx.getDepth(); ++i) {
		if (nodeIdx.getIdxAt(i) >= retrieved->getChildCount())
			return nullptr;

		retrieved = retrieved->getChildAt(nodeIdx.getIdxAt(i));
	}

	return static_cast<TYPE *> (retrieved);
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
