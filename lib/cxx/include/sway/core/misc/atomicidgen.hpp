#ifndef SWAY_CORE_MISC_ATOMICIDGEN_HPP
#define SWAY_CORE_MISC_ATOMICIDGEN_HPP

#include <sway/_stdafx.hpp>
#include <sway/defines.hpp>
#include <sway/numeraltypes.hpp>

namespace sway::core {

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

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_ATOMICIDGEN_HPP