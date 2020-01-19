#include <sway/core/containers/hierarchynode.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

template<typename TYPE>
TYPE * HierarchyNode::getChild(const std::string & nodeUid) const {
	std::vector<HierarchyNode *>::const_iterator iter = _children.begin();
	while (iter != _children.end()) {
		if ((*iter)->getNodeUid().compare(nodeUid) == 0)
			break;

		iter++;
	}

	if (iter != _children.end())
		return static_cast<TYPE *> (*iter);

	return nullptr;
}

template<typename TYPE>
TYPE * HierarchyNode::getChildAt(u32_t targetIdx) const {
	if (targetIdx >= 0 && targetIdx < _children.size())
		return static_cast<TYPE *> (_children[targetIdx]);

	return nullptr;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
