#ifndef SWAY_CORE_UTIL_TYPEDEFS_HPP
#define SWAY_CORE_UTIL_TYPEDEFS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

DECLARE_PTR_TYPES(Traverser)
DECLARE_PTR_TYPES(Visitable)
DECLARE_PTR_TYPES(Observer)

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_TYPEDEFS_HPP
