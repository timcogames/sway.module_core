#ifndef SWAY_CORE_MISC_HASH_HPP
#define SWAY_CORE_MISC_HASH_HPP

#include <sway/namespacemacros.hpp>

#include <cstddef>
#include <functional>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

// Golden ratio constant for hashing
#define HASH_GOLDEN_RATIO 0x9e3779b9

template <typename TYPE, typename... REST>
inline void hashCombine(std::size_t &seed, const TYPE &val, REST &&...rest) {
  seed ^= std::hash<TYPE>{}(val) + HASH_GOLDEN_RATIO + (seed << 6) + (seed >> 2);
  (hashCombine(seed, rest), ...);
}

template <typename... REST>
inline auto hashValue(REST &&...rest) -> std::size_t {
  std::size_t seed{0};
  (hashCombine(seed, rest), ...);
  return seed;
}

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_HASH_HPP
