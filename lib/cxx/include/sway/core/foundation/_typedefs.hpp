#ifndef SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
#define SWAY_CORE_FOUNDATION_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

// clang-format off

class Subsystem;
namespace SubsystemTypedefs {
using SharedPtr_t = std::shared_ptr<Subsystem>;
using Container_t = std::unordered_map<std::string, SharedPtr_t>;
template <class TYPE> using OptionalSharedPtr_t = std::optional<std::shared_ptr<TYPE>>;
}  // namespace SubsystemTypedefs

// clang-format on

class Context;
namespace typedefs::context {
using Ptr_t = Context *;
}  // namespace typedefs::context

class Object;
namespace typedefs::object {
using Ptr_t = Object *;
}  // namespace typedefs::object

class ObjectClassMetadata;
namespace ObjectClassMetadataTypedefs {
using ConstPtr_t = const ObjectClassMetadata *;
}  // namespace ObjectClassMetadataTypedefs

class EventData;
namespace EventDataTypedefs {
using Ptr_t = EventData *;
}  // namespace EventDataTypedefs

class Eventable;
namespace EventableTypedefs {
using Ptr_t = Eventable *;
}  // namespace EventableTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
