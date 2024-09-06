#ifndef SWAY_CORE_FOUNDATION_CONTEXT_HPP
#define SWAY_CORE_FOUNDATION_CONTEXT_HPP

#include <sway/classpointermacros.hpp>
#include <sway/core/foundation/subsystem.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <optional>
#include <string>
#include <unordered_map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context {
  DECLARE_CLASS_POINTER_ALIASES(Context)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Context() = default;

  ~Context() { subsystems_.clear(); }

#pragma endregion

  void registerSubsystem(Subsystem::SharedPtr_t obj) { subsystems_.insert(std::make_pair(obj->getClassname(), obj)); }

  void unregisterSubsystem(const std::string &classname) {
    auto iter = subsystems_.find(classname);
    if (iter != subsystems_.end()) {
      subsystems_.erase(iter);
    }
  }

  template <class TYPE>
  auto getSubsystem(const std::string &classname) const -> std::optional<std::shared_ptr<TYPE>> {
    static_assert(std::is_base_of<Subsystem, TYPE>::value, "Provided type does not implement Subsystem");

    auto iter = subsystems_.find(classname);
    if (iter != subsystems_.end()) {
      return std::static_pointer_cast<TYPE>(iter->second);
    }

    return std::nullopt;
  }

  template <class TYPE>
  auto getSubsystem() const -> std::optional<std::shared_ptr<TYPE>> {
    return this->getSubsystem<TYPE>(TYPE::getObjectClassMetadata()->getClassname());
  }

  void initialize() {
    for (const auto &[_, subsystem] : subsystems_) {
      auto initialized = subsystem->initialize();
      if (!initialized) {
      }
    }
  }

  void tick(f32_t timestep) {
    for (const auto &[_, subsystem] : subsystems_) {
      subsystem->tick(timestep);
    }
  }

  void shutdown() {
    for (const auto &[_, subsystem] : subsystems_) {
      subsystem->shutdown();
    }
  }

private:
  std::unordered_map<std::string, Subsystem::SharedPtr_t> subsystems_;  // Контейнер объектов.
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_CONTEXT_HPP
