#ifndef SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
#define SWAY_CORE_EVTS_SUBSCRIBABLE_HPP

#include <sway/core/events/eventhandler.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(evts)

class Subscribable {
protected:
  std::vector<EventHandler *> subscriptions_;

public:
  using Subscriber = decltype(subscriptions_)::iterator;

  auto subscribe(EventHandler *handler) -> Subscriber { return subscriptions_.insert(subscriptions_.end(), handler); }

  void unsubscribe(Subscriber subscriber) { subscriptions_.erase(subscriber); }

  void handle(const std::unique_ptr<foundation::Event> &event) {
    for (auto &handler : this->subscriptions_) {
      handler->invoke(event);
    }
  }
};

NAMESPACE_END(evts)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
