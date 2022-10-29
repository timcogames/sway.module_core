#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventaction.hpp>
#include <sway/core/foundation/eventactionmapper.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

#include <gtest/gtest.h>

#include <any>
#include <iostream>
#include <memory>

#define EVT_CREATED (0)

using namespace sway;
using namespace sway::core;

class BaseEvent : public foundation::Event {
public:
  DECLARE_CLASS_METADATA(BaseEvent, foundation::Event)

  BaseEvent(u32_t type, void *userdata)
      : id_(misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      , type_(type)
      , userdata_(userdata) {}

  virtual ~BaseEvent() = default;

  MTHD_OVERRIDE(std::string getId() const) { return id_; }

  MTHD_OVERRIDE(u32_t getType() const) { return type_; }

  MTHD_OVERRIDE(void *getUserData() const) { return userdata_; }

private:
  std::string id_;
  u32_t type_;
  void *userdata_;
};

struct MyEventUserData : public foundation::EventUserData {
  std::string value;

  MTHD_OVERRIDE(std::string serialize() const) { return ""; }
};

class MyCreatedEvent : public BaseEvent {
public:
  DECLARE_CLASS_METADATA(MyCreatedEvent, BaseEvent)

  MyCreatedEvent()
      : BaseEvent(EVT_CREATED, nullptr) {}

  MyCreatedEvent(void *userdata)
      : BaseEvent(EVT_CREATED, userdata) {}
};

class MyModelState : public foundation::EventActionMapper<foundation::EventAction<MyCreatedEvent>> {
public:
  MyModelState() = default;

  virtual ~MyModelState() = default;

  MTHD_OVERRIDE(void apply(std::shared_ptr<MyCreatedEvent> vent)) {
    myvalue_ = vent->getConcreteUserData<MyEventUserData>().value;
  }

  [[nodiscard]] std::string getMyValue() const { return myvalue_; }

private:
  std::string myvalue_;
};

class MyModel {
public:
  MyModel() {
    applier_ = std::make_shared<foundation::EventApplier>();
    state_ = std::make_shared<MyModelState>();
    state_->registerEvents(applier_.get());
  }

  ~MyModel() = default;

  void raiseEvent(std::shared_ptr<foundation::Event> evt, bool &applied) { applier_->applyEvent(evt, applied); }

  std::shared_ptr<MyModelState> getState() { return state_; }

private:
  std::shared_ptr<foundation::EventApplier> applier_;
  std::shared_ptr<MyModelState> state_;
};

class ModelTest : public ::testing::Test {
protected:
  void SetUp() override { model = std::make_shared<MyModel>(); }

  void TearDown() override {}

  std::shared_ptr<MyModel> model;
};

TEST_F(ModelTest, Event) {
  bool applied;

  MyEventUserData userdata;
  userdata.value = std::string("test");
  model->raiseEvent(std::make_shared<MyCreatedEvent>(&userdata), applied);
  ASSERT_TRUE(applied);
}
