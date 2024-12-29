#include <sway/core/events/models/messagebodyserializable.hpp>
#include <sway/core/events/models/messageformats.hpp>
#include <sway/core/foundation/eventdata.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

struct CustomEventData {
  std::string value;
};

struct MessageBodyJsonSerializer final : public Deserializer {
#pragma region "Overridden Deserializer methods"

  virtual auto deserialize(const std::string &data) -> DeserializerTypedefs::OutResult_t {
    auto *eventData = (CustomEventData *)malloc(sizeof(CustomEventData));
    eventData->value = "test";
    return eventData;
  }

#pragma endregion
};

TEST(EventData, deserializer) {
  auto jsonSerializer = std::make_shared<MessageBodyJsonSerializer>();
  auto jsonEventData = EventData::create(MessageFormat::JSON, jsonSerializer);
  jsonEventData.body->data = "{\"test\": \"value\"}";

  auto jsonBody = std::static_pointer_cast<MessageBodySerializable>(jsonEventData.body);
  auto testEventData = jsonBody->toObject<CustomEventData>();

  EXPECT_EQ(testEventData.value, "test");
}
