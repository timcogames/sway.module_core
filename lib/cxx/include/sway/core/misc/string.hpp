#ifndef SWAY_CORE_MISC_STRING_HPP
#define SWAY_CORE_MISC_STRING_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::transform
#include <cctype>  // std::tolower
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

inline auto toLowerCase(const std::string &str) -> std::string {
  std::string result = str;
  std::transform(str.cbegin(), str.cend(), result.begin(), [=](u8_t chr) { return std::tolower(chr); });
  return result;
}

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_MISC_STRING_HPP
