#ifndef SWAY_CORE_MISC_GUID_HPP
#define SWAY_CORE_MISC_GUID_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

namespace constans {

constexpr std::string_view UID_BUCKET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

constexpr i32_t UUID_MAGIC_SIZE = 4;
constexpr std::array<i32_t, UUID_MAGIC_SIZE> UUID_MAGIC = {8, 4, 4, 12};

/**
 * @brief \~english The "nil" UUID is a UUID in which all 128 bits are set to zero. \~russian "Нулевой" UUID - UUID, в
 * котором все 128 битов установлены в ноль.
 */
constexpr std::string_view UUID_MAGIC_ZERO = "00000000-0000-0000-0000-000000000000";

}  // namespace constans

template <std::size_t SIZE>
FORCE_INLINE auto newGuid(const std::array<i32_t, SIZE> &format) -> std::string {
  std::string result;
  auto iter = format.begin();
  while (iter != format.end()) {
    if (iter != format.begin()) {
      result += '-';
    }

    for (auto i = 0; i < *iter; ++i) {
      result += constans::UID_BUCKET[rand() % constans::UID_BUCKET.size()];
    }

    ++iter;
  }

  return result;
}

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_GUID_HPP
