#include <sway/core/container/hierarchy.hpp>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

void Hierarchy::registerEmClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<Hierarchy>("Hierarchy")
        .constructor()
        .class_function("findNode", &Hierarchy::findNode, emscripten::allow_raw_pointers())
        .function("getRootNode", &Hierarchy::getRootNode, emscripten::allow_raw_pointers())
        .function("setRootNode", &Hierarchy::setRootNode, emscripten::allow_raw_pointers());
#endif
}

Hierarchy::Hierarchy() { root_ = std::make_shared<Node>(); }

std::optional<std::shared_ptr<Node>> Hierarchy::findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx) {
    std::optional<std::shared_ptr<Node>> retrieved = parent;
    for (int i = NODEIDX_ROOT_DEPTH; i < nodeIdx.getDepth(); ++i) {
        if (nodeIdx.getIdxAt(i) >= retrieved->get()->getNumOfChildNodes()) {
            return std::nullopt;
        }

        retrieved = retrieved->get()->getChildAt(nodeIdx.getIdxAt(i)).value();
    }

    return retrieved;
}

std::shared_ptr<Node> Hierarchy::getRootNode() { return root_; }

void Hierarchy::setRootNode(std::shared_ptr<Node> root) { root_ = root; }

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
