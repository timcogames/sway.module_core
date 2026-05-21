#ifndef SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
#define SWAY_CORE_EVENTS_V2_EVENTDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/messagebodydeserializable.hpp>
#include <sway/core/events/models/messagecontent.hpp>
#include <sway/core/events/v2/_typedefs.hpp>

namespace sway::core::v2 {

struct UserData {
  void *raw;
};

template <typename TYPE>
class EventData : public UserData {};

template <>
struct EventData<MessageContent> : public UserData {
  static auto create(MessageBodyFormat format, DeserializerSharedPtr_t deserializer) -> EventData {
    EventData data;
    data.content.format = format;
    data.content.body = std::make_shared<MessageBodyDeserializable>(deserializer);
    return data;
  }

  MessageContent content;
};

template <>
struct EventData<Dictionary> : public UserData {
  Dictionary content;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
