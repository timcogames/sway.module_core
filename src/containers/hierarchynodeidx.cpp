#include <sway/core/containers/hierarchynodeidx.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

HierarchyNodeIdx::HierarchyNodeIdx(std::vector<s32_t> indexes)
	: _indexes(indexes) {
	// Empty
}

HierarchyNodeIdx::HierarchyNodeIdx(const HierarchyNodeIdx & parent, s32_t idx)
	: _indexes(parent._indexes) {

	_indexes.push_back(idx);
}

HierarchyNodeIdx HierarchyNodeIdx::getParent() const {
	std::vector<s32_t> parentIndexes = _indexes;
	parentIndexes.pop_back();
	return HierarchyNodeIdx(parentIndexes);
}

s32_t HierarchyNodeIdx::getDepth() const {
	return (s32_t) _indexes.size();
}

s32_t HierarchyNodeIdx::getIdxAt(int idx) const {
		return _indexes[idx];
}

bool HierarchyNodeIdx::isValid() const {
	return getDepth() > 0;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
