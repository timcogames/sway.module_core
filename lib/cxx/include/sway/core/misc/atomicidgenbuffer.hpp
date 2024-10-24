#ifndef SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP
#define SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP

#include <sway/core/misc/atomicidgen.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

#include <atomic>
#include <functional>
#include <memory>
#include <queue>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

class AtomicIdGenBuffer {
public:
#pragma region "Ctors/Dtor"

  AtomicIdGenBuffer()
      : uniqId_(0) {}

  DTOR_DEFAULT(AtomicIdGenBuffer);

#pragma endregion

  void increment(u32_t uid) { usages_[uid].fetch_add(1, std::memory_order_relaxed); }

  void free(u32_t uid, std::function<void(bool)> dispose) {
    auto iter = usages_.find(uid);
    if (iter == usages_.end()) {
      dispose(false);
      return;
    }

    iter->second.fetch_sub(1, std::memory_order_relaxed);
    if (iter->second == GLOB_UID_INVALID) {
      freeds_.push(uid);
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
  std::queue<u32_t> freeds_;
  std::unordered_map<u32_t, std::atomic_uint32_t> usages_;
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_ATOMICIDGENBUFFER_HPP