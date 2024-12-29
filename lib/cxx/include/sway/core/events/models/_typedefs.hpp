#ifndef SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP
#define SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/dictionary.hpp>

namespace sway::core {

using MessageUserData_t = Dictionary;
class MessageBody;
namespace MessageBodyTypedefs {
using SharedPtr_t = std::shared_ptr<MessageBody>;
}  // namespace MessageBodyTypedefs

class EventData;
namespace EventDataTypedefs {
using Ref_t = const EventData &;
using Container_t = std::vector<EventData>;
using ContainerRef_t = const Container_t &;
}  // namespace EventDataTypedefs

class Deserializer;
namespace DeserializerTypedefs {
using SharedPtr_t = std::shared_ptr<Deserializer>;
using OutResult_t = void *;
}  // namespace DeserializerTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP
