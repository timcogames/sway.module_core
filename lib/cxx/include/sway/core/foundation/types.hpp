#ifndef SWAY_CORE_FOUNDATION_TYPES_HPP
#define SWAY_CORE_FOUNDATION_TYPES_HPP

#include <sway/classpointermacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

DECLARE_CLASS_POINTER_TYPES(Context)
DECLARE_CLASS_POINTER_TYPES(Subsystem)
DECLARE_CLASS_POINTER_TYPES(Event)
DECLARE_CLASS_POINTER_TYPES(Eventable)
DECLARE_CLASS_POINTER_TYPES(EventHandler)

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_TYPES_HPP
