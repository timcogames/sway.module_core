#ifndef SWAY_CORE_FOUNDATION_TYPES_HPP
#define SWAY_CORE_FOUNDATION_TYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

DECLARE_PTR_TYPES(Context)
DECLARE_PTR_TYPES(Subsystem)
DECLARE_PTR_TYPES(Event)
DECLARE_PTR_TYPES(Eventable)
DECLARE_PTR_TYPES(EventHandler)

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_TYPES_HPP
