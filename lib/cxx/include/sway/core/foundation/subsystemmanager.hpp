#ifndef SWAY_CORE_FOUNDATION_SUBSYSTEMMANAGER_HPP
#define SWAY_CORE_FOUNDATION_SUBSYSTEMMANAGER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/subsystem.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/emscriptenmacros.hpp>

namespace sway::core {

class SubsystemManager {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  SubsystemManager() = default;

  virtual ~SubsystemManager();

  /** @} */
#pragma endregion

  void registerSubsystem(SubsystemTypedefs::SharedPtr_t obj);

  void unregisterSubsystem(const std::string &classname);

  template <class TYPE>
  [[nodiscard]] auto getSubsystem(const std::string &classname) const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE>;

  template <class TYPE>
  [[nodiscard]] auto getSubsystem() const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE>;

  void initialize();

  void tick(f32_t timestep);

  void shutdown();

private:
  SubsystemTypedefs::Container_t subsystems_;
};

}  // namespace sway::core

#include <sway/core/foundation/subsystemmanager.inl>

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEMMANAGER_HPP
