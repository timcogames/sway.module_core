#include <sway/core/container/hierarchy.hpp>

#ifdef _EMSCRIPTEN
	#include <emscripten/emscripten.h>
	#include <emscripten/bind.h>
	#include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

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
	: _root(nullptr) { }

std::shared_ptr<Node> Hierarchy::findNode(std::shared_ptr<Node> root, const NodeIdx & nodeIdx) {
	std::shared_ptr<Node> retrieved = root;
	for (int i = 1/* пропускаем корневой индекс */; i < nodeIdx.getDepth(); ++i) {
		if (nodeIdx.getIdxAt(i) >= retrieved->getNumOfChildNodes())
			return nullptr;

		retrieved = retrieved->getChildAt(nodeIdx.getIdxAt(i)).value();
	}

	return retrieved;
}

std::shared_ptr<Node> Hierarchy::getRootNode() {
	return _root;
}

void Hierarchy::setRootNode(std::shared_ptr<Node> root) {
	_root = root;
}

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
