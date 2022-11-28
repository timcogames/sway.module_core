#ifndef SWAY_CORE_FOUNDATION_EVENTDATA_HPP
#define SWAY_CORE_FOUNDATION_EVENTDATA_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

struct EventData {
  // clang-format off
  PURE_VIRTUAL(auto serialize() const -> std::string);  // clang-format on

  PURE_VIRTUAL(void deserialize(const std::string &jdata));
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTDATA_HPP
