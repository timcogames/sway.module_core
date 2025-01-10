#include <sway/core/foundation/declareeventmacros.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventaction.hpp>
#include <sway/core/foundation/eventactionmapper.hpp>
#include <sway/core/foundation/eventhandlerimpl.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

#include <gtest/gtest.h>

#define EVT_CREATED (0)

NS_SHORT_SWAY()
NS_SHORT(core)

struct MyEventData : public EventData {
  std::string value;
};

class BaseEvent : public Event {
  DECLARE_CLASS_METADATA(BaseEvent, Event)

public:
#pragma region "Ctors/Dtor"

  BaseEvent(u32_t type, MyEventData *data)
      : id_(newGuid<constans::UUID_MAGIC_SIZE>(constans::UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  virtual ~BaseEvent() = default;

#pragma endregion

#pragma region "Implementation Event methods"

  virtual auto getId() const -> std::string { return id_; }

  virtual auto getType() const -> u32_t { return type_; }

  virtual auto getData() const -> EventDataTypedefs::Ptr_t { return data_; }

#pragma endregion

private:
  std::string id_;
  u32_t type_;
  MyEventData *data_;
};

class MyCreatedEvent : public BaseEvent {
  DECLARE_CLASS_METADATA(MyCreatedEvent, BaseEvent)

public:
  MyCreatedEvent()
      : BaseEvent(EVT_CREATED, nullptr) {}

  MyCreatedEvent(MyEventData *userdata)
      : BaseEvent(EVT_CREATED, userdata) {}
};

class MyModelState : public EventActionMapper<EventAction<MyCreatedEvent>> {
public:
#pragma region "Ctors/Dtor"

  MyModelState() = default;

  virtual ~MyModelState() = default;

#pragma endregion

#pragma region "Overridden EventActionMapper methods"

  MTHD_VIRTUAL_OVERRIDE(void apply(std::shared_ptr<MyCreatedEvent> vent)) { myvalue_ = vent->getConcreteData<MyEventData>().value; }

#pragma endregion

  [[nodiscard]] auto getMyValue() const -> std::string { return myvalue_; }

private:
  std::string myvalue_;
};

class MyModel {
public:
#pragma region "Ctors/Dtor"

  MyModel() {
    applier_ = std::make_shared<EventApplier>();
    state_ = std::make_shared<MyModelState>();
    state_->registerEvents(applier_.get());
  }

  ~MyModel() = default;

#pragma endregion

  void raiseEvent(EventTypedefs::SharedPtr_t evt, bool &applied) { applier_->applyEvent(evt, applied); }

  auto getState() -> std::shared_ptr<MyModelState> { return state_; }

private:
  std::shared_ptr<EventApplier> applier_;
  std::shared_ptr<MyModelState> state_;
};

class ModelTest : public ::testing::Test {
protected:
#pragma region "Overridden Test methods"

  MTHD_OVERRIDE(void SetUp()) { model = std::make_shared<MyModel>(); }

  MTHD_OVERRIDE(void TearDown()) {}

#pragma endregion

  std::shared_ptr<MyModel> model;
};

TEST_F(ModelTest, reise_event) {
  bool applied;

  MyEventData userdata;
  userdata.value = std::string("test");
  model->raiseEvent(std::make_shared<MyCreatedEvent>(&userdata), applied);
  ASSERT_TRUE(applied);
}

//-------------------------------------------

struct TestEventData : public EventData {
  i32_t prev;
  i32_t next;
};

class TestSender : public Eventable {
  DECLARE_EVENT(VALUE_CHANGED, ValueChanged)

public:
  TestSender() = default;

  void setValue() {
    TestEventData eventdata;
    eventdata.prev = 2;
    eventdata.next = 5;
    emit(VALUE_CHANGED, std::make_unique<ValueChangedEvent>(0, &eventdata), [&](EventHandlerTypedefs::Ptr_t handler) {
      std::cout << "EXECUTE:" << std::endl;
      return true;
    });
  }

  auto handleValueChanged(const EventTypedefs::UniquePtr_t &evt) -> bool {
    std::cout << "TestReceiver handleValueChanged:" << std::endl;
    return true;
  }
};

class TestReceiver : public Eventable {
  DECLARE_EVENT(VALUE_CHANGED, ValueChanged)

public:
  auto handleValueChanged(const EventTypedefs::UniquePtr_t &evt) -> bool {
    std::cout << "TestReceiver handleValueChanged:" << std::endl;
    return true;
  }
};

TEST(AttributeTest, subscribe) {
  auto *testReceiver = new TestReceiver();
  auto *testSender = new TestSender();

  testSender->subscribe(testReceiver, "ValueChanged",
      (new TEventHandlerImpl<TestReceiver>(testReceiver, &TestReceiver::handleValueChanged)));

  testSender->subscribe(
      testSender, "ValueChanged", (new TEventHandlerImpl<TestSender>(testSender, &TestSender::handleValueChanged)));

  testSender->setValue();
}
