#ifndef SWAY_CORE_CONTAINER_TYPES_HPP
#define SWAY_CORE_CONTAINER_TYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

class Node;
class Hierarchy;

using NodePtr_t = Node *;
using NodeWeakPtr_t = std::weak_ptr<Node>;
using NodeSharedPtr_t = std::shared_ptr<Node>;

using HierarchyPtr_t = Hierarchy *;
using HierarchySharedPtr_t = std::shared_ptr<Hierarchy>;

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_TYPES_HPP
