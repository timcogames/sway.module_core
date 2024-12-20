#ifndef SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP
#define SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/_typedefs.hpp>
#include <sway/core/misc/atomicidgen.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

namespace sway::core {

class AtomicIdGenBuffer {
public:
#pragma region "Ctors/Dtor"

  AtomicIdGenBuffer()
      : uniqId_(0) {}

  ~AtomicIdGenBuffer() = default;

#pragma endregion

  void increment(u32_t id) { usages_[id].fetch_add(1, std::memory_order_relaxed); }

  void free(u32_t id, AtomicIdGenBufferTypedefs::DisposeFunc_t dispose) {
    auto iter = usages_.find(id);
    if (iter == usages_.end()) {
      dispose(false);
      return;
    }

    iter->second.fetch_sub(1, std::memory_order_relaxed);
    if (iter->second == GLOB_UID_INVALID) {
      freeds_.push(id);
      usages_.erase(iter);
      dispose(true);
    }
  }

  [[nodiscard]] auto current() const -> u32_t { return uniqId_; }

  auto next() -> u32_t {
    if (!freeds_.empty()) {
      uniqId_ = freeds_.front();
      freeds_.pop();
    } else {
      uniqId_ = AtomicIdGen::next();
    }

    return uniqId_;
  }

protected:
  u32_t uniqId_;
  AtomicIdGenBufferTypedefs::FreedContainer_t freeds_;
  AtomicIdGenBufferTypedefs::UsageContainer_t usages_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP