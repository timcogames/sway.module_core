#ifndef SWAY_CORE_EVTS_EVENTBUS_HPP
#define SWAY_CORE_EVTS_EVENTBUS_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/_typedefs.hpp>
#include <sway/core/events/subscribable.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>

namespace sway::core {

class EventBus : public Subscribable {
public:
#pragma region "Ctors/Dtor"

  ~EventBus() = default;

#pragma endregion

  void addToQueue(EventTypedefs::UniquePtr_t event) { events_.emplace(std::move(event)); }

  void process() {
    while (!events_.empty()) {
      const auto &event = events_.front();

      this->handle(event);
      events_.pop();
    }
  }

private:
  EventTypedefs::QueueUniquePtr_t events_{};
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVTS_EVENTBUS_HPP
