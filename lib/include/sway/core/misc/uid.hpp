#ifndef SWAY_CORE_MISC_UID_HPP
#define SWAY_CORE_MISC_UID_HPP

#include <sway/core/misc/format.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <array>
#include <cstdlib>  // rand
#include <string>  // std::string

constexpr int UUID_NBR_OF_GROUPS = 4;
constexpr std::array<int, UUID_NBR_OF_GROUPS> UUID_MAGIC = {8, 4, 4, 12};
constexpr std::string_view UUID_ZERO = "00000000-0000-0000-0000-000000000000";

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

template <std::size_t NBR>
inline auto randomUid(const std::array<int, NBR> &format) {
  static const std::string bucket = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::string result;
  auto iter = format.begin();
  while (iter != format.end()) {
    if (iter != format.begin()) {
      result += '-';
    }

    for (int i = 0; i < *iter; ++i) {
      result += bucket[rand() % bucket.size()];
    }

    ++iter;
  }

  return result;
}

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
