#ifndef SWAY_CORE_MISC_GUID_HPP
#define SWAY_CORE_MISC_GUID_HPP

#include <sway/core/misc/format.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <array>
#include <cstdlib>  // rand
#include <string>  // std::string

constexpr sway::i32_t UUID_NBR_OF_GROUPS = 4;
constexpr std::array<sway::i32_t, UUID_NBR_OF_GROUPS> UUID_MAGIC = {8, 4, 4, 12};
constexpr std::string_view UUID_ZERO = "00000000-0000-0000-0000-000000000000";

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

template <std::size_t NBR>
inline auto newGuid(const std::array<i32_t, NBR> &format) {
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

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_GUID_HPP
