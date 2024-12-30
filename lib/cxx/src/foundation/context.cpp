#include <sway/core/foundation/context.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Context)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Context>("Context").constructor<>();
#endif
EMSCRIPTEN_BINDING_END()

Context::~Context() { subsystems_.clear(); }

void Context::registerSubsystem(SubsystemTypedefs::SharedPtr_t obj) {
  subsystems_.insert(std::make_pair(obj->getClassname(), obj));
}

void Context::unregisterSubsystem(const std::string &classname) {
  auto iter = subsystems_.find(classname);
  if (iter != subsystems_.end()) {
    subsystems_.erase(iter);
  }
}

void Context::initialize() {
  for (const auto &[_, subsystem] : subsystems_) {
    auto initialized = subsystem->initialize();
    if (!initialized) {
    }
  }
}

void Context::tick(f32_t timestep) {
  for (const auto &[_, subsystem] : subsystems_) {
    subsystem->tick(timestep);
  }
}

void Context::shutdown() {
  for (const auto &[_, subsystem] : subsystems_) {
    subsystem->shutdown();
  }
}

}  // namespace sway::core
