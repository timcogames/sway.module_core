#ifndef SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/enumeratormacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(intrusive)

DECLARE_ENUM(Priority, LOW = 10, NORMAL = 20, HIGH = 30)

NS_END()  // namespace intrusive
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
