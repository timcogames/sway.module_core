#ifndef SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP
#define SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/dictionary.hpp>

namespace sway::core {

class MessageBody;

using MessageBodySharedPtr_t = std::shared_ptr<MessageBody>;

class Deserializer;

using DeserializerSharedPtr_t = std::shared_ptr<Deserializer>;
using DeserializerOutResult_t = void *;

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_TYPEDEFS_HPP
