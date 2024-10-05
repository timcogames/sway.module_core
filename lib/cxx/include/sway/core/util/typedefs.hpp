#ifndef SWAY_CORE_UTIL_TYPEDEFS_HPP
#define SWAY_CORE_UTIL_TYPEDEFS_HPP

#include <sway/classpointermacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

DECLARE_CLASS_POINTER_TYPES(Traverser)
DECLARE_CLASS_POINTER_TYPES(Visitable)
DECLARE_CLASS_POINTER_TYPES(Observer)

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_TYPEDEFS_HPP
