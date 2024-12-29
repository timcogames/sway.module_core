#include <sway/core/events/eventbus.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/guid.hpp>

#include <gtest/gtest.h>

#include <memory>
#include <string>

NS_SHORT_SWAY()
NS_SHORT(core)

struct TestEventData : EventData {
  std::string value;
};

class TestEvent : public foundation::Event {
  DECLARE_CLASS_METADATA(TestEvent, foundation::Event)

public:
#pragma region "Ctors/Dtor"

  TestEvent(u32_t type, EventDataTypedefs::Ptr_t data)
      : id_(newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~TestEvent() = default;

#pragma endregion

#pragma region "Overridden Event methods"

  MTHD_VIRTUAL_OVERRIDE(auto id() const -> std::string) { return id_; }

  MTHD_VIRTUAL_OVERRIDE(auto type() const -> u32_t) { return type_; }

  MTHD_VIRTUAL_OVERRIDE(auto data() const -> EventDataTypedefs::Ptr_t ) { return data_; }

#pragma endregion

private:
  std::string id_;
  u32_t type_;
  EventDataTypedefs::Ptr_t data_;
};

struct TestEventHandler : public evts::EventHandler {
  ~TestEventHandler() override = default;

#pragma region "Overridden EventHandler methods"

  MTHD_VIRTUAL_OVERRIDE(auto invoke(const foundation::Event::UniquePtr_t &event) -> bool) final {
    std::cout << static_cast<TestEventData *>(event->data())->value.c_str() << std::endl;
    return true;
  }

#pragma endregion
};

class EventBusTest : public ::testing::Test {
protected:
#pragma region "Overridden Test methods"

  MTHD_OVERRIDE(void SetUp()) { evtbus_ = new evts::EventBus(); }

  MTHD_OVERRIDE(void TearDown()) { SAFE_DELETE_OBJECT(evtbus_); }

#pragma endregion

  evts::EventBus::Ptr_t evtbus_;
};

TEST_F(EventBusTest, add_event) {
  auto *eventdata = new TestEventData();
  eventdata->value = "test";

  auto subscriber = this->evtbus_->subscribe(new TestEventHandler());

  auto event = std::make_unique<TestEvent>(0, eventdata);
  this->evtbus_->addToQueue(std::move(event));

  this->evtbus_->process();
}
