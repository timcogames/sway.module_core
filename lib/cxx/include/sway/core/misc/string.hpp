#ifndef SWAY_CORE_MISC_STRING_HPP
#define SWAY_CORE_MISC_STRING_HPP

#include <sway/inlinemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::transform
#include <cctype>  // std::tolower
#include <cstdio>  // snprintf
#include <cstdlib>  // atoi, atof
#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

FORCE_INLINE auto toLowerCase(const std::string &str) -> std::string {
  std::string result = str;
  std::transform(str.cbegin(), str.cend(), result.begin(), [=](u8_t chr) { return std::tolower(chr); });
  return result;
}

FORCE_INLINE auto toString(i32_t val) -> std::string {
  char buff[256];
  snprintf(buff, 256, "%d", val);

  return buff;
}

FORCE_INLINE auto toString(f32_t val) -> std::string {
  char buff[256];
  snprintf(buff, 256, "%f", val);

  return buff;
}

FORCE_INLINE auto toString(lpcstr_t str, const std::string &def) -> std::string {
  if (str == nullptr) {
    return def;
  }

  return str;
}

FORCE_INLINE auto toInteger(lpcstr_t str, i32_t def) -> i32_t {
  if (str == nullptr) {
    return def;
  }

  return atoi(str);
}

FORCE_INLINE auto toFloat(lpcstr_t str, f32_t def) -> f32_t {
  if (str == nullptr) {
    return def;
  }

  return (f32_t)atof(str);
}

FORCE_INLINE auto toBoolean(lpcstr_t str, bool def) -> bool {
  if (str == nullptr) {
    return def;
  }

  return toLowerCase(str) == "true" ? true : false;
}

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_STRING_HPP
