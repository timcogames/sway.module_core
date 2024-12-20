#ifndef SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP
#define SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/_typedefs.hpp>
#include <sway/core/misc/atomicidgenbuffer.hpp>
#include <sway/defines.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

namespace sway::core {

template <typename TYPE>
class AtomicIdGenManager : public AtomicIdGenBuffer {
public:
#pragma region "Ctors"

  AtomicIdGenManager() = default;

  ~AtomicIdGenManager() { performDeletion(); }

#pragma endregion

  auto add(const std::string &name, AtomicIdGenManagerTypedefs::UniquePtr_t<TYPE> &&ptr) -> u32_t {
    const auto id = getId(name);
    if (id != GLOB_UID_INVALID) {
      increment(id);
      return id;
    }

    next();
    increment(current());

    nameToId_.emplace(name, current());
    idToUniquePtr_.emplace(current(), std::move(ptr));

    return nameToId_[name];
  }

  void removeId_(u32_t id) {
    auto pred = [id](const auto &pair) { return pair.second == id; };
    auto iter = std::find_if(nameToId_.begin(), nameToId_.end(), pred);
    if (iter != nameToId_.end()) {
      nameToId_.erase(iter);
    }
  }

  void remove(u32_t id) {
    auto iter = idToUniquePtr_.find(id);
    if (iter != idToUniquePtr_.end()) {
      free(id, [&](bool rejected) {
        if (rejected) {
          ownerships_.push(std::move(iter->second));
          idToUniquePtr_.erase(iter);
          removeId_(id);
        }
      });
    }
  }

  auto getId(const std::string &name) -> u32_t {
    auto iter = nameToId_.find(name);
    if (iter != nameToId_.end()) {
      return iter->second;
    }

    return GLOB_UID_INVALID;
  }

  auto get(u32_t id) -> const AtomicIdGenManagerTypedefs::UniquePtr_t<TYPE> & {
    const auto iter = idToUniquePtr_.find(id);
    if (iter != idToUniquePtr_.end()) {
      return iter->second;
    }

    return nullptr;
  }

  auto get(const std::string &name) -> const AtomicIdGenManagerTypedefs::UniquePtr_t<TYPE> & {
    const auto id = getId(name);
    if (id != GLOB_UID_INVALID) {
      return get(id);
    }

    return nullptr;
  }

  void performDeletion() {
    while (!ownerships_.empty()) {
      ownerships_.pop();
    }
  }

private:
  AtomicIdGenManagerTypedefs::QueueUniquePtr_t<TYPE> ownerships_;
  AtomicIdGenManagerTypedefs::NameToId_t nameToId_;
  AtomicIdGenManagerTypedefs::IdToUniquePtr_t<TYPE> idToUniquePtr_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP