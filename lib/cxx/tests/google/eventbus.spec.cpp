#include <sway/core/events/eventbus.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/guid.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>

using namespace sway;
using namespace sway::core;

struct TestEventData : foundation::EventData {
  std::string value;

  // clang-format off
  MTHD_OVERRIDE(auto serialize() const -> std::string) {  // clang-format on
    return "";
  }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}
};

class TestEvent : public foundation::Event {
public:
  DECLARE_CLASS_METADATA(TestEvent, foundation::Event)

  TestEvent(u32_t type, foundation::EventData *data)
      : id_(misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~TestEvent() = default;

  // clang-format off
  MTHD_OVERRIDE(auto id() const -> std::string) {  // clang-format on
    return id_;
  }

  // clang-format off
  MTHD_OVERRIDE(auto type() const -> u32_t) {  // clang-format on
    return type_;
  }

  // clang-format off
  MTHD_OVERRIDE(auto data() const -> foundation::EventData *) {  // clang-format on
    return data_;
  }

private:
  std::string id_;
  u32_t type_;
  foundation::EventData *data_;
};

struct TestEventHandler : public evts::EventHandler {
  ~TestEventHandler() override = default;

  // clang-format off
  MTHD_OVERRIDE(auto invoke(const std::unique_ptr<foundation::Event> &event) -> bool) final {  // clang-format on
    std::cout << static_cast<TestEventData *>(event->data())->value.c_str() << std::endl;
    return true;
  }
};

class EventBusTest : public ::testing::Test {
protected:
  void SetUp() override { evtbus_ = new evts::EventBus(); }

  void TearDown() override { SAFE_DELETE_OBJECT(evtbus_); }

  evts::EventBus *evtbus_;
};

TEST_F(EventBusTest, AddEvent) {
  auto *eventdata = new TestEventData();
  eventdata->value = "test";

  auto subscriber = this->evtbus_->subscribe(new TestEventHandler());

  auto event = std::make_unique<TestEvent>(0, eventdata);
  this->evtbus_->addToQueue(std::move(event));

  this->evtbus_->process();
}
