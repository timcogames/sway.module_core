#ifndef SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
#define SWAY_CORE_EVTS_SUBSCRIBABLE_HPP

#include <sway/core/events/eventhandler.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(evts)

class Subscribable {
protected:
  std::vector<EventHandler::Ptr_t> subscriptions_;

public:
  using Subscriber_t = decltype(subscriptions_)::iterator;

  auto subscribe(EventHandler::Ptr_t handler) -> Subscriber_t;

  void unsubscribe(Subscriber_t subscriber);

  void handle(const foundation::Event::UniquePtr_t &evt);
};

NS_END()  // namespace evts
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
