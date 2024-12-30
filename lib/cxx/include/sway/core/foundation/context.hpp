#ifndef SWAY_CORE_FOUNDATION_CONTEXT_HPP
#define SWAY_CORE_FOUNDATION_CONTEXT_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/subsystem.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/emscriptenmacros.hpp>

namespace sway::core {

class Context {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Context() = default;

  ~Context();

#pragma endregion

  void registerSubsystem(SubsystemTypedefs::SharedPtr_t obj);

  void unregisterSubsystem(const std::string &classname);

  template <class TYPE>
  auto getSubsystem(const std::string &classname) const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE>;

  template <class TYPE>
  auto getSubsystem() const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE>;

  void initialize();

  void tick(f32_t timestep);

  void shutdown();

private:
  SubsystemTypedefs::Container_t subsystems_;
};

}  // namespace sway::core

#include <sway/core/foundation/context.inl>

#endif  // SWAY_CORE_FOUNDATION_CONTEXT_HPP
