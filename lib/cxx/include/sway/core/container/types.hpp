#ifndef SWAY_CORE_CONTAINER_TYPES_HPP
#define SWAY_CORE_CONTAINER_TYPES_HPP

#include <sway/classpointermacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

DECLARE_CLASS_POINTER_TYPES(Node)
DECLARE_CLASS_POINTER_TYPES(Hierarchy)

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_TYPES_HPP
