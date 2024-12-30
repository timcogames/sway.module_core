#include <sway/core/foundation/subsystem.hpp>

namespace sway::core {

template <class TYPE>
auto Context::getSubsystem(const std::string &classname) const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE> {
  static_assert(std::is_base_of<Subsystem, TYPE>::value, "Provided type does not implement Subsystem");

  auto iter = subsystems_.find(classname);
  if (iter != subsystems_.end()) {
    return std::static_pointer_cast<TYPE>(iter->second);
  }

  return std::nullopt;
}

template <class TYPE>
auto Context::getSubsystem() const -> SubsystemTypedefs::OptionalSharedPtr_t<TYPE> {
  return this->getSubsystem<TYPE>(TYPE::getObjectClassMetadata()->getClassname());
}

}  // namespace sway::core
