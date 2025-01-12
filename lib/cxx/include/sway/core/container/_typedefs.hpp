#ifndef SWAY_CORE_CONTAINER_TYPEDEFS_HPP
#define SWAY_CORE_CONTAINER_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>
#include <sway/common/numeraltypes.hpp>

namespace sway::core {

class NodeData;
namespace NodeDataTypedefs {}  // namespace NodeDataTypedefs

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class NodeIndex;
namespace NodeIndexTypedefs {
using Optional_t = std::optional<NodeIndex>;
}  // namespace NodeIndexTypedefs

namespace NodeIndexChainTypedefs {
using Item_t = i32_t;
using Container_t = std::vector<Item_t>;
}  // namespace NodeIndexChainTypedefs

class Node;
namespace NodeTypedefs {
using Ptr_t = Node *;
using WeakPtr_t = std::weak_ptr<Node>;
using SharedPtr_t = std::shared_ptr<Node>;
using OptionalSharedPtr_t = std::optional<SharedPtr_t>;
using Container_t = std::vector<SharedPtr_t>;
using JsPtr_t = intptr_t;
using JsPtrArray_t = JsPtr_t *;
}  // namespace NodeTypedefs

class Hierarchy;
namespace HierarchyTypedefs {
using Ptr_t = Hierarchy *;
using JsPtr_t = intptr_t;
}  // namespace HierarchyTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_TYPEDEFS_HPP
