#ifndef SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
#define SWAY_CORE_EVTS_SUBSCRIBABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/_typedefs.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>

namespace sway::core {

class Subscribable {
protected:
  EventHandlerTypedefs::Container_t subscriptions_;

public:
  using Subscriber_t = decltype(subscriptions_)::iterator;

  ~Subscribable() { subscriptions_.clear(); }

  auto subscribe(EventHandlerTypedefs::Ptr_t handler) -> Subscriber_t;

  void unsubscribe(Subscriber_t subscriber);

  void handle(EventTypedefs::UniquePtr_t &evt);
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVTS_SUBSCRIBABLE_HPP
