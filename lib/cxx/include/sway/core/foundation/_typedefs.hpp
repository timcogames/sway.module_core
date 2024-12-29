#ifndef SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
#define SWAY_CORE_FOUNDATION_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

class ObjectClassMetadata;
namespace ObjectClassMetadataTypedefs {
using ConstPtr_t = const ObjectClassMetadata *;
}  // namespace ObjectClassMetadataTypedefs

class EventData;
namespace EventDataTypedefs {
using Ptr_t = EventData *;
}  // namespace EventDataTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
