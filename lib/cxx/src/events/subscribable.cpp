#include <sway/core/events/subscribable.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(evts)

auto Subscribable::subscribe(EventHandler::Ptr_t handler) -> Subscriber_t {
  return subscriptions_.insert(subscriptions_.end(), handler);
}

void Subscribable::unsubscribe(Subscriber_t subscriber) { subscriptions_.erase(subscriber); }

void Subscribable::handle(const foundation::Event::UniquePtr_t &evt) {
  for (auto &handler : this->subscriptions_) {
    handler->invoke(evt);
  }
}

NAMESPACE_END(evts)
NAMESPACE_END(core)
NAMESPACE_END(sway)
