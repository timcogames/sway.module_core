#ifndef SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/enumeratormacros.hpp>

namespace sway::core {

// clang-format off
#define PRIORITY_LIST(ITEM) \
  ITEM(LOW, 10) \
  ITEM(NORMAL, 20) \
  ITEM(HIGH, 30)
// clang-format on

DECLARE_ENUM_U32(Priority, PRIORITY_LIST)

}  // namespace sway::core

#endif  // SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
