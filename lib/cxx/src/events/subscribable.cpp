#include <sway/core/events/subscribable.hpp>

namespace sway::core {

auto Subscribable::subscribe(EventHandlerTypedefs::Ptr_t handler) -> Subscriber_t {
  return subscriptions_.insert(subscriptions_.end(), handler);
}

void Subscribable::unsubscribe(Subscriber_t subscriber) { subscriptions_.erase(subscriber); }

void Subscribable::handle(const EventTypedefs::UniquePtr_t &evt) {
  for (auto &handler : this->subscriptions_) {
    handler->invoke(evt);
  }
}

}  // namespace sway::core
