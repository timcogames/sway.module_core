#ifndef SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
#define SWAY_CORE_EVENTS_V2_EVENTDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/messagebodydeserializable.hpp>
#include <sway/core/events/models/messagecontent.hpp>

namespace sway::core::v2 {

struct Rawable {
  void *userdata;
};

template <typename TYPE>
class EventData {};

template <>
struct EventData<MessageContent> : public Rawable {
  static auto create(MessageBodyFormat format, DeserializerSharedPtr_t deserializer) -> EventData {
    EventData data;
    data.content.format = format;
    data.content.body = std::make_shared<MessageBodyDeserializable>(deserializer);
    return data;
  }

  MessageContent content;
};

template <>
struct EventData<Dictionary> : public Rawable {
  Dictionary content;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
