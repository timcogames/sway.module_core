#include <sway/core/events/_typedefs.hpp>
#include <sway/core/events/eventbus.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/memory/safedelete.hpp>
#include <sway/core/misc/guid.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

struct TestEventData : EventData {
  std::string value;
};

class TestEvent : public Event {
  DECLARE_CLASS_METADATA(TestEvent, Event)

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  TestEvent(u32_t type, EventDataTypedefs::Ptr_t data)
      : id_(newGuid<constans::UUID_MAGIC_SIZE>(constans::UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  ~TestEvent() override = default;

  /** @} */
#pragma endregion

#pragma region "Implementation Event methods"

  [[nodiscard]] auto getId() const -> std::string override { return id_; }

  [[nodiscard]] auto getType() const -> u32_t override { return type_; }

  [[nodiscard]] auto getData() const -> EventDataTypedefs::Ptr_t override { return data_; }

#pragma endregion

private:
  std::string id_;
  u32_t type_;
  EventDataTypedefs::Ptr_t data_;
};

struct TestEventHandler : public EventHandler {

  TestEventHandler()
      : EventHandler(nullptr) {}

  ~TestEventHandler() override = default;

#pragma region "Implementation EventHandler methods"

  virtual auto invoke(EventTypedefs::UniquePtr_t &&evt) -> bool final {
    std::cout << static_cast<TestEventData *>(evt->getData())->value.c_str() << std::endl;
    return true;
  }

#pragma endregion
};

class EventBusTest : public ::testing::Test {
protected:
#pragma region "Overridden Test methods"

  MTHD_OVERRIDE(void SetUp()) { evtbus_ = new EventBus(); }

  MTHD_OVERRIDE(void TearDown()) { safeDelete<EventBus>(evtbus_); }

#pragma endregion

  EventBusTypedefs::Ptr_t evtbus_;
};

TEST_F(EventBusTest, add_event) {
  auto *eventdata = new TestEventData();
  eventdata->value = "test";

  auto subscriber = this->evtbus_->subscribe(new TestEventHandler());

  auto event = std::make_unique<TestEvent>(0, eventdata);
  this->evtbus_->addToQueue(std::move(event));

  this->evtbus_->process();
}
