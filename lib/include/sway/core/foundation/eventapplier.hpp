#ifndef SWAY_CORE_FOUNDATION_EVENTAPPLIER_HPP
#define SWAY_CORE_FOUNDATION_EVENTAPPLIER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventaction.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

#include <functional>
#include <map>
#include <memory>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class EventApplier {
public:
  template <class TConcreteEvent>
  void registerEvent(EventAction<TConcreteEvent> *ctx) {
    auto eventClassname = TConcreteEvent::getObjectClassMetadata()->getClassname();
    auto func = [=](std::shared_ptr<Event> evt) { ctx->apply(std::static_pointer_cast<TConcreteEvent>(evt)); };
    appliers_.insert(std::make_pair(eventClassname, func));
  }

  void applyEvent(std::shared_ptr<Event> evt, bool &applied) {
    auto *data = evt->data();
    if (data == nullptr) {
      printf("ERROR: [EventApplier::applyEvent -> %s]\n\t- data is not valid\n", evt->getClassname().c_str());
      applied = false;
      return;
    }

    auto callbackFunc = appliers_[evt->getClassname()];
    if (!callbackFunc) {
      printf("ERROR: [EventApplier::applyEvent -> %s]\n\t- callbackFunc is not valid\n", evt->getClassname().c_str());
      applied = false;
      return;
    }

    callbackFunc(evt);
    applied = true;
  }

  auto eventset() -> std::map<std::string, std::function<void(std::shared_ptr<Event>)>> { return appliers_; }

private:
  std::map<std::string, std::function<void(std::shared_ptr<Event>)>> appliers_;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
