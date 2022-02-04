#include <sway/core/containers/hierarchy.hpp>

#ifdef _EMSCRIPTEN
	#include <emscripten/emscripten.h>
	#include <emscripten/bind.h>
	#include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

void Hierarchy::registerEmsClass() {
#ifdef _EMSCRIPTEN
	emscripten::class_<Hierarchy>("Hierarchy")
		.constructor()
		.class_function("findNode", &Hierarchy::findNode, emscripten::allow_raw_pointers())
		.function("getRootNode", &Hierarchy::getRootNode, emscripten::allow_raw_pointers())
		.function("setRootNode", &Hierarchy::setRootNode, emscripten::allow_raw_pointers());
#endif
}

Hierarchy::Hierarchy()
	: _root(nullptr) {
	// Empty
}

Hierarchy::~Hierarchy() {
	SAFE_DELETE(_root)
}

Node * Hierarchy::findNode(Node * root, const NodeIdx & nodeIdx) {
	Node * retrieved = root;
	for (int i = 1/* пропускаем корневой индекс */; i < nodeIdx.getDepth(); ++i) {
		if (nodeIdx.getIdxAt(i) >= retrieved->getChildCount())
			return nullptr;

		retrieved = retrieved->getChildAt(nodeIdx.getIdxAt(i));
	}

	return retrieved;
}

Node * Hierarchy::getRootNode() {
	return _root;
}

void Hierarchy::setRootNode(Node * root) {
	_root = root;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
