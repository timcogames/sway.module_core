#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEBODYDESERIALIZER_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEBODYDESERIALIZER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/_typedefs.hpp>
#include <sway/core/events/models/io/serialization/deserializer.hpp>
#include <sway/core/events/models/messagebody.hpp>

namespace sway::core {

template <typename TYPE, typename = void>
struct IsAggregateStruct : std::false_type {};

template <typename TYPE>
struct IsAggregateStruct<TYPE, std::enable_if_t<std::is_class_v<std::remove_reference_t<TYPE>> &&
                                                std::is_aggregate_v<std::remove_reference_t<TYPE>>>> : std::true_type {
};

struct MessageBodyDeserializable final : public MessageBody {
  DeserializerSharedPtr_t deserializer;

  MessageBodyDeserializable(DeserializerSharedPtr_t deserializer)
      : deserializer(deserializer) {}

  template <typename TYPE, std::enable_if_t<IsAggregateStruct<TYPE>::value, i32_t> = 0>
  auto toConcreteObject() -> TYPE {
    return *reinterpret_cast<TYPE *>(deserializer->deserialize(data));
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEBODYDESERIALIZER_HPP
