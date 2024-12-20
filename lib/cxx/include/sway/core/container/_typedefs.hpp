#ifndef SWAY_CORE_CONTAINER_TYPEDEFS_HPP
#define SWAY_CORE_CONTAINER_TYPEDEFS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>

#include <optional>

namespace sway::core {

class NodeIndex;
namespace NodeIndexTypedefs {
using Optional_t = std::optional<NodeIndex>;
}  // namespace NodeIndexTypedefs

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

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

DECLARE_PTR_TYPES(Node)
DECLARE_PTR_TYPES(Hierarchy)

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_TYPEDEFS_HPP
