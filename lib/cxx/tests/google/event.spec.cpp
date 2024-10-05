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

#include <any>
#include <iostream>
#include <memory>
#include <string>

#define EVT_CREATED (0)

NS_SHORT_SWAY()
NS_SHORT(core)

struct MyEventData : public foundation::EventData {
  std::string value;

#pragma region "Override EventData methods"

  MTHD_VIRTUAL_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  MTHD_VIRTUAL_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

class BaseEvent : public foundation::Event {
  DECLARE_CLASS_METADATA(BaseEvent, foundation::Event)

public:
#pragma region "Ctors/Dtor"

  BaseEvent(u32_t type, MyEventData *data)
      : id_(misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , data_(data) {}

  virtual ~BaseEvent() = default;

#pragma endregion

#pragma region "Override Event methods"

  MTHD_VIRTUAL_OVERRIDE(auto id() const -> std::string) { return id_; }

  MTHD_VIRTUAL_OVERRIDE(auto type() const -> u32_t) { return type_; }

  MTHD_VIRTUAL_OVERRIDE(auto data() const -> foundation::EventData::Ptr_t) { return data_; }

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

class MyModelState : public foundation::EventActionMapper<foundation::EventAction<MyCreatedEvent>> {
public:
#pragma region "Ctors/Dtor"

  MyModelState() = default;

  virtual ~MyModelState() = default;

#pragma endregion

#pragma region "Override EventActionMapper methods"

  MTHD_VIRTUAL_OVERRIDE(void apply(std::shared_ptr<MyCreatedEvent> vent)) { myvalue_ = vent->getConcreteData<MyEventData>().value; }

#pragma endregion

  [[nodiscard]]
  auto getMyValue() const -> std::string {
    return myvalue_;
  }

private:
  std::string myvalue_;
};

class MyModel {
public:
#pragma region "Ctors/Dtor"

  MyModel() {
    applier_ = std::make_shared<foundation::EventApplier>();
    state_ = std::make_shared<MyModelState>();
    state_->registerEvents(applier_.get());
  }

  ~MyModel() = default;

#pragma endregion

  void raiseEvent(foundation::Event::SharedPtr_t evt, bool &applied) { applier_->applyEvent(evt, applied); }

  auto getState() -> std::shared_ptr<MyModelState> { return state_; }

private:
  std::shared_ptr<foundation::EventApplier> applier_;
  std::shared_ptr<MyModelState> state_;
};

class ModelTest : public ::testing::Test {
protected:
#pragma region "Override Test methods"

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

struct TestEventData : public foundation::EventData {
  i32_t prev;
  i32_t next;

#pragma region "Override EventData methods"

  MTHD_VIRTUAL_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  MTHD_VIRTUAL_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

class TestSender : public core::foundation::Eventable {
  DECLARE_EVENT(VALUE_CHANGED, ValueChanged)

public:
  TestSender() = default;

  void setValue() {
    TestEventData eventdata;
    eventdata.prev = 2;
    eventdata.next = 5;
    emit(VALUE_CHANGED, new ValueChangedEvent(0, &eventdata), [&](core::foundation::EventHandler::Ptr_t handler) {
      std::cout << "EXECUTE:" << std::endl;
      return true;
    });
  }

  void handleValueChanged(core::foundation::Event::Ptr_t evt) {
    std::cout << "TestReceiver handleValueChanged:" << std::endl;
  }
};

class TestReceiver : public core::foundation::Eventable {
  DECLARE_EVENT(VALUE_CHANGED, ValueChanged)

public:
  void handleValueChanged(core::foundation::Event::Ptr_t evt) {
    std::cout << "TestReceiver handleValueChanged:" << std::endl;
  }
};

TEST(AttributeTest, subscribe) {
  auto *testReceiver = new TestReceiver();
  auto *testSender = new TestSender();

  testSender->subscribe(testReceiver, "ValueChanged",
      (new core::foundation::TEventHandlerImpl<TestReceiver>(testReceiver, &TestReceiver::handleValueChanged)));

  testSender->subscribe(testSender, "ValueChanged",
      (new core::foundation::TEventHandlerImpl<TestSender>(testSender, &TestSender::handleValueChanged)));

  testSender->setValue();
}
