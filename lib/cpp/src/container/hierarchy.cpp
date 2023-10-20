#include <sway/core/container/hierarchy.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

EMSCRIPTEN_BINDING_BEGIN(Hierarchy)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<NodeData>("NodeData").property("nodeidx", &NodeData::nodeidx);

emscripten::register_vector<NodeData>("NodeDataVec");

emscripten::class_<Hierarchy>("Hierarchy")
    .constructor()
    .class_function("findNode", &Hierarchy::findNode, emscripten::allow_raw_pointers())
    .function("getRootNode", &Hierarchy::getRootNode, emscripten::allow_raw_pointers())
    .function("setRootNode", &Hierarchy::setRootNode, emscripten::allow_raw_pointers());
#endif
EMSCRIPTEN_BINDING_END()

Hierarchy::Hierarchy() { root_ = std::make_shared<Node>(); }

auto Hierarchy::findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx) -> std::optional<std::shared_ptr<Node>> {
  std::optional<std::shared_ptr<Node>> retrieved = parent;
  for (int i = NODEIDX_ROOT_DEPTH; i < nodeIdx.getDepth(); ++i) {
    if (nodeIdx.getIdxAt(i) >= retrieved->get()->getNumOfChildNodes()) {
      return std::nullopt;
    }

    retrieved = retrieved->get()->getChildAt(nodeIdx.getIdxAt(i)).value();
  }

  return retrieved;
}

auto Hierarchy::getRootNode() -> std::shared_ptr<Node> { return root_; }

void Hierarchy::setRootNode(std::shared_ptr<Node> root) { root_ = root; }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createHierarchy() -> Hierarchy::JsPtr_t { return Hierarchy::toJs(new Hierarchy()); }

void deleteHierarchy(Hierarchy::JsPtr_t hierarchy) {
  auto obj = Hierarchy::fromJs(hierarchy);
  SAFE_DELETE_OBJECT(obj);
}

auto getRootNode(Hierarchy::JsPtr_t hierarchy) -> Node::JsPtr_t {
  auto obj = Hierarchy::fromJs(hierarchy);
  return Node::toJs(obj->getRootNode().get());
}

#endif

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
