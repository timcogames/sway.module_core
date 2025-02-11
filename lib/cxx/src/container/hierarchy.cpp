#include <sway/core/container/hierarchy.hpp>
#include <sway/core/memory/safedelete.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

namespace sway::core {

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

auto Hierarchy::findNode(NodeSharedPtr_t parent, const NodeIndex &nodeIdx) -> NodeOptionalSharedPtr_t {
  NodeOptionalSharedPtr_t retrieved = parent;
  for (auto i = NODEIDX_ROOT_DEPTH; i < nodeIdx.getDepth(); ++i) {
    if (nodeIdx.getIndexAt(i) >= retrieved->get()->getNumOfChildNodes()) {
      return std::nullopt;
    }

    retrieved = retrieved->get()->getChildAt(nodeIdx.getIndexAt(i)).value();
  }

  return retrieved;
}

auto Hierarchy::getRootNode() -> NodeSharedPtr_t { return root_; }

void Hierarchy::setRootNode(NodeSharedPtr_t root) { root_ = root; }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createHierarchy() -> HierarchyJsPtr_t { return Hierarchy::toJs(new Hierarchy()); }

void deleteHierarchy(HierarchyJsPtr_t hierarchy) {
  auto obj = Hierarchy::fromJs(hierarchy);
  safeDelete<HierarchyPtr_t>(obj);
}

auto getRootNode(HierarchyJsPtr_t hierarchy) -> NodeJsPtr_t {
  auto obj = Hierarchy::fromJs(hierarchy);
  return Node::toJs(obj->getRootNode());
}

#endif

}  // namespace sway::core
