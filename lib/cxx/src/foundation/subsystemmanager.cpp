#include <sway/core/foundation/subsystemmanager.hpp>

namespace sway::core {

SubsystemManager::~SubsystemManager() { subsystems_.clear(); }

void SubsystemManager::registerSubsystem(SubsystemTypedefs::SharedPtr_t obj) {
  subsystems_.insert(std::make_pair(obj->getClassname(), obj));
}

void SubsystemManager::unregisterSubsystem(const std::string &classname) {
  auto iter = subsystems_.find(classname);
  if (iter != subsystems_.end()) {
    subsystems_.erase(iter);
  }
}

void SubsystemManager::initialize() {
  for (const auto &[_, subsystem] : subsystems_) {
    auto initialized = subsystem->initialize();
    if (!initialized) {
    }
  }
}

void SubsystemManager::tick(f32_t timestep) {
  for (const auto &[_, subsystem] : subsystems_) {
    subsystem->tick(timestep);
  }
}

void SubsystemManager::shutdown() {
  for (const auto &[_, subsystem] : subsystems_) {
    subsystem->shutdown();
  }
}

}  // namespace sway::core
