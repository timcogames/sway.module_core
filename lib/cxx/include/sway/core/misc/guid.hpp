#ifndef SWAY_CORE_MISC_GUID_HPP
#define SWAY_CORE_MISC_GUID_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

constexpr sway::i32_t UUID_NBR_OF_GROUPS = 4;
constexpr std::array<sway::i32_t, UUID_NBR_OF_GROUPS> UUID_MAGIC = {8, 4, 4, 12};
constexpr std::string_view UUID_ZERO = "00000000-0000-0000-0000-000000000000";

namespace sway::core {

template <std::size_t SIZE>
FORCE_INLINE auto newGuid(const std::array<i32_t, SIZE> &format) -> std::string {
  static const std::string bucket = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::string result;
  auto iter = format.begin();
  while (iter != format.end()) {
    if (iter != format.begin()) {
      result += '-';
    }

    for (auto i = 0; i < *iter; ++i) {
      result += bucket[rand() % bucket.size()];
    }

    ++iter;
  }

  return result;
}

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_GUID_HPP
