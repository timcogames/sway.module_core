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
  template <class EVENT>
  void registerEvent(EventAction<EVENT> *ctx) {
    auto eventClassname = EVENT::getObjectClassMetadata()->getClassname();
    auto func = [=](Event::SharedPtr_t evt) { ctx->apply(std::static_pointer_cast<EVENT>(evt)); };
    appliers_.insert(std::make_pair(eventClassname, func));
  }

  void applyEvent(Event::SharedPtr_t evt, bool &applied) {
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

  auto eventset() -> std::map<std::string, std::function<void(Event::SharedPtr_t)>> { return appliers_; }

private:
  std::map<std::string, std::function<void(Event::SharedPtr_t)>> appliers_;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTAPPLIER_HPP
