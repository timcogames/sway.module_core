#ifndef SWAY_CORE_CONTAINER_TYPEDEFS_HPP
#define SWAY_CORE_CONTAINER_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>
#include <sway/common/numeraltypes.hpp>

namespace sway::core {

class NodeData;

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class NodeIndex;

using NodeIndexOptional_t = std::optional<NodeIndex>;

using NodeIndexChainItem_t = i32_t;
using NodeIndexChainContainer_t = std::vector<NodeIndexChainItem_t>;

class Node;

using NodePtr_t = Node *;
using NodeWeakPtr_t = std::weak_ptr<Node>;
using NodeSharedPtr_t = std::shared_ptr<Node>;
using NodeOptionalSharedPtr_t = std::optional<NodeSharedPtr_t>;
using NodeContainer_t = std::vector<NodeSharedPtr_t>;
using NodeJsPtr_t = intptr_t;
using NodeJsPtrArray_t = NodeJsPtr_t *;

class Hierarchy;

using HierarchyPtr_t = Hierarchy *;
using HierarchyJsPtr_t = intptr_t;

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_TYPEDEFS_HPP
