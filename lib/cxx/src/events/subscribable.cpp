#include <sway/core/events/subscribable.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(evts)

auto Subscribable::subscribe(EventHandler::Ptr_t handler) -> Subscriber_t {
  return subscriptions_.insert(subscriptions_.end(), handler);
}

void Subscribable::unsubscribe(Subscriber_t subscriber) { subscriptions_.erase(subscriber); }

void Subscribable::handle(const foundation::Event::UniquePtr_t &evt) {
  for (auto &handler : this->subscriptions_) {
    handler->invoke(evt);
  }
}

NS_END()  // namespace evts
NS_END()  // namespace core
NS_END()  // namespace sway
