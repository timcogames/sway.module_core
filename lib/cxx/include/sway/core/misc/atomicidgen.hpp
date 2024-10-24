#ifndef SWAY_CORE_MISC_ATOMICIDGEN_HPP
#define SWAY_CORE_MISC_ATOMICIDGEN_HPP

#include <sway/defines.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

#include <atomic>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

class IdGen {
public:
  static auto next() noexcept -> u32_t {
    static u32_t counter{0};
    u32_t current;
    do {
      current = ++counter;
    } while (current == GLOB_UID_INVALID);

    return current;
  }
};

class AtomicIdGen {
public:
  static auto next() noexcept -> u32_t {
    static std::atomic_uint32_t counter{0};
    u32_t current;
    do {
      current = counter.fetch_add(1, std::memory_order_relaxed);
    } while (current == GLOB_UID_INVALID);

    return current;
  }
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_ATOMICIDGEN_HPP