#ifndef SWAY_CORE_MISC_HASH_HPP
#define SWAY_CORE_MISC_HASH_HPP

#include <sway/_stdafx.hpp>
#include <sway/inlinemacros.hpp>

namespace sway::core {

// Golden ratio constant for hashing
#define HASH_GOLDEN_RATIO 0x9e3779b9

template <typename TYPE, typename... REST>
FORCE_INLINE void hashCombine(std::size_t &seed, const TYPE &val, REST &&...rest) {
  seed ^= std::hash<TYPE>{}(val) + HASH_GOLDEN_RATIO + (seed << 6) + (seed >> 2);
  (hashCombine(seed, rest), ...);
}

template <typename... REST>
FORCE_INLINE auto hashValue(REST &&...rest) -> std::size_t {
  std::size_t seed{0};
  (hashCombine(seed, rest), ...);
  return seed;
}

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_HASH_HPP
