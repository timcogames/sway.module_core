#ifndef SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
#define SWAY_CORE_EVENTS_V2_EVENTDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/messagebodyserializable.hpp>
#include <sway/core/events/models/messagecontent.hpp>

namespace sway::core::v2 {

class EventData : public MessageContent {
public:
  static auto create(MessageFormat format, DeserializerTypedefs::SharedPtr_t deserializer) -> EventData {
    EventData data;
    data.format = format;
    data.body = std::make_shared<MessageBodySerializable>(deserializer);
    return data;
  }
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTDATA_HPP
