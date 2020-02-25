#include <sway/core/containers/nodeidx.h>

#ifdef _EMSCRIPTEN
	#include <emscripten/emscripten.h>
	#include <emscripten/bind.h>
	#include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

void NodeIdx::registerEmsClass() {
#ifdef _EMSCRIPTEN
	emscripten::class_<NodeIdx>("NodeIdx")
		.constructor<>()
		.constructor<std::vector<s32_t>>()
		.constructor<NodeIdx, s32_t>()
		.function("getParent", &NodeIdx::getParent, emscripten::allow_raw_pointers())
		.function("getDepth", &NodeIdx::getDepth)
		.function("isValid", &NodeIdx::isValid);
#endif
}

NodeIdx::NodeIdx(std::vector<s32_t> indexes)
	: indexes_(indexes) {
	// Empty
}

NodeIdx::NodeIdx(const NodeIdx & parent, s32_t idx)
	: indexes_(parent.indexes_) {

	indexes_.push_back(idx);
}

NodeIdx NodeIdx::getParent() const {
	std::vector<s32_t> parentIndexes = indexes_;
	parentIndexes.pop_back();
	return NodeIdx(parentIndexes);
}

s32_t NodeIdx::getDepth() const {
	return (s32_t) indexes_.size();
}

s32_t NodeIdx::getIdxAt(int idx) const {
		return indexes_[idx];
}

bool NodeIdx::isValid() const {
	return getDepth() > 0;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
