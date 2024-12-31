#ifndef SWAY_CORE_FOUNDATION_EVENTDATA_HPP
#define SWAY_CORE_FOUNDATION_EVENTDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/io/serialization/deserializer.hpp>
#include <sway/core/events/models/io/serialization/serializer.hpp>
#include <sway/core/events/models/messagebodyserializable.hpp>
#include <sway/core/events/models/messagecontent.hpp>
#include <sway/emscriptenmacros.hpp>

namespace sway::core {

class EventData : public MessageContent, public Serializer, public Deserializer {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  static auto create(MessageFormat format, DeserializerTypedefs::SharedPtr_t deserializer) -> EventData {
    EventData data;
    data.format = format;
    data.body = std::make_shared<MessageBodySerializable>(deserializer);
    return data;
  }

#pragma region "Overridden Serializer, Deserializer methods"

  virtual auto serialize() const -> std::string { return ""; }

  virtual auto deserialize(const std::string &data) -> DeserializerTypedefs::OutResult_t { return nullptr; }

#pragma endregion
};

#include <sway/core/foundation/eventdata_embind.inl>

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENTDATA_HPP
