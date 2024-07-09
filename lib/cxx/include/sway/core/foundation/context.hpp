#ifndef SWAY_CORE_FOUNDATION_CONTEXT_HPP
#define SWAY_CORE_FOUNDATION_CONTEXT_HPP

#include <sway/core/foundation/subsystem.hpp>
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
public:
  DECLARE_EMSCRIPTEN_BINDING()

  Context() = default;

  ~Context() { subsystems_.clear(); }

  void registerSubsystem(std::shared_ptr<Subsystem> obj) {
    subsystems_.insert(std::make_pair(obj->getClassname(), obj));
  }

  void unregisterSubsystem(const std::string &classname) {
    auto iter = subsystems_.find(classname);
    if (iter != subsystems_.end()) {
      subsystems_.erase(iter);
    }
  }

  template <class TConcreteSubsystem>
  auto getSubsystem(const std::string &classname) const -> std::optional<std::shared_ptr<TConcreteSubsystem>> {
    static_assert(std::is_base_of<Subsystem, TConcreteSubsystem>::value, "Provided type does not implement Subsystem");

    auto iter = subsystems_.find(classname);
    if (iter != subsystems_.end()) {
      return std::static_pointer_cast<TConcreteSubsystem>(iter->second);
    }

    return std::nullopt;
  }

  template <class TConcreteSubsystem>
  auto getSubsystem() const -> std::optional<std::shared_ptr<TConcreteSubsystem>> {
    return this->getSubsystem<TConcreteSubsystem>(TConcreteSubsystem::getObjectClassMetadata()->getClassname());
  }

  void initialize() {
    for (const auto &[_, subsystem] : subsystems_) {
      auto initialized = subsystem->initialize();
      if (!initialized) {
      }
    }
  }

  void tick(float timestep) {
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
  std::unordered_map<std::string, std::shared_ptr<Subsystem>> subsystems_;  // Контейнер объектов.
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_CONTEXT_HPP
