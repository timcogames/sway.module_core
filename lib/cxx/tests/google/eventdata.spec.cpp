#include <sway/core/events/models/messagebodydeserializable.hpp>
#include <sway/core/events/models/messagebodyformats.hpp>
#include <sway/core/foundation/eventdata.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

struct CustomEventData {
  std::string value;
};

struct MessageBodyJsonDeserializer final : public Deserializer {
#pragma region "Overridden Deserializer methods"

  virtual auto deserialize(const std::string &data) -> DeserializerOutResult_t {
    auto *eventData = (CustomEventData *)malloc(sizeof(CustomEventData));
    eventData->value = "test";
    return eventData;
  }

#pragma endregion
};

TEST(EventData, deserializer) {
  auto jsonDeserializer = std::make_shared<MessageBodyJsonDeserializer>();
  auto jsonEventData = EventData::create(MessageBodyFormat::JSON, jsonDeserializer);
  jsonEventData.body->data = "{\"test\": \"value\"}";

  auto jsonBody = std::static_pointer_cast<MessageBodyDeserializable>(jsonEventData.body);
  auto testEventData = jsonBody->toConcreteObject<CustomEventData>();

  EXPECT_EQ(testEventData.value, "test");
}
