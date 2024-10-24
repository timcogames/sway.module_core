#ifndef SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP
#define SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP

#include <sway/core/misc/atomicidgenbuffer.hpp>
#include <sway/defines.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

template <typename TYPE>
class AtomicIdGenManager : public misc::AtomicIdGenBuffer {
public:
#pragma region "Typedefs"

  using UniquePtr_t = std::unique_ptr<TYPE>;

#pragma endregion

#pragma region "Ctors/Dtor"

  DTOR(AtomicIdGenManager) { performDeletion(); }

#pragma endregion

  auto add(const std::string &name, std::unique_ptr<TYPE> &&obj) -> u32_t {
    const auto uid = getUid(name);
    if (uid != GLOB_UID_INVALID) {
      increment(uid);
      return uid;
    }

    next();
    increment(current());

    nameToId_.emplace(name, current());
    idToObject_.emplace(current(), std::move(obj));

    return nameToId_[name];
  }

  void removeUid_(u32_t uid) {
    auto pred = [uid](const auto &pair) { return pair.second == uid; };
    auto iter = std::find_if(nameToId_.begin(), nameToId_.end(), pred);
    if (iter != nameToId_.end()) {
      nameToId_.erase(iter);
    }
  }

  void remove(u32_t uid) {
    auto iter = idToObject_.find(uid);
    if (iter != idToObject_.end()) {
      free(uid, [&](bool rejected) {
        if (rejected) {
          ownerships_.push(std::move(iter->second));
          idToObject_.erase(iter);
          removeUid_(uid);
        }
      });
    }
  }

  auto getUid(const std::string &name) -> u32_t {
    auto iter = nameToId_.find(name);
    if (iter != nameToId_.end()) {
      return iter->second;
    }

    return GLOB_UID_INVALID;
  }

  auto get(u32_t uid) -> const std::unique_ptr<TYPE> & {
    const auto iter = idToObject_.find(uid);
    if (iter != idToObject_.end()) {
      return iter->second;
    }

    return nullptr;
  }

  auto get(const std::string &name) -> const std::unique_ptr<TYPE> & {
    const auto uid = getUid(name);
    if (uid != GLOB_UID_INVALID) {
      return get(uid);
    }

    return nullptr;
  }

  void performDeletion() {
    while (!ownerships_.empty()) {
      ownerships_.pop();
    }
  }

private:
  std::queue<std::unique_ptr<TYPE>> ownerships_;
  std::unordered_map<std::string, u32_t> nameToId_;
  std::unordered_map<u32_t, std::unique_ptr<TYPE>> idToObject_;
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_ATOMICIDGENMANAGER_HPP