#include <sway/core/container/hierarchy.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

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

auto Hierarchy::findNode(Node::SharedPtr_t parent, const NodeIdx &nodeIdx) -> std::optional<Node::SharedPtr_t> {
  std::optional<Node::SharedPtr_t> retrieved = parent;
  for (auto i = NODEIDX_ROOT_DEPTH; i < nodeIdx.getDepth(); ++i) {
    if (nodeIdx.getIdxAt(i) >= retrieved->get()->getNumOfChildNodes()) {
      return std::nullopt;
    }

    retrieved = retrieved->get()->getChildAt(nodeIdx.getIdxAt(i)).value();
  }

  return retrieved;
}

auto Hierarchy::getRootNode() -> Node::SharedPtr_t { return root_; }

void Hierarchy::setRootNode(Node::SharedPtr_t root) { root_ = root; }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createHierarchy() -> Hierarchy::JavaScriptPtr_t { return Hierarchy::toJs(new Hierarchy()); }

void deleteHierarchy(Hierarchy::JavaScriptPtr_t hierarchy) {
  auto obj = Hierarchy::fromJs(hierarchy);
  SAFE_DELETE_OBJECT(obj);
}

auto getRootNode(Hierarchy::JavaScriptPtr_t hierarchy) -> Node::JavaScriptPtr_t {
  auto obj = Hierarchy::fromJs(hierarchy);
  return Node::toJs(obj->getRootNode());
}

#endif

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway
