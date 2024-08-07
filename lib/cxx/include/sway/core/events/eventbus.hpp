#ifndef SWAY_CORE_EVTS_EVENTBUS_HPP
#define SWAY_CORE_EVTS_EVENTBUS_HPP

#include <sway/core/events/eventhandler.hpp>
#include <sway/core/events/subscribable.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>
#include <queue>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(evts)

class EventBus : public Subscribable {
public:
  using Ptr_t = EventBus *;
  using SharedPtr_t = std::shared_ptr<EventBus>;

#pragma region "Ctors/Dtor"

  ~EventBus() = default;

#pragma endregion

  void addToQueue(foundation::Event::UniquePtr_t event) { events_.emplace(std::move(event)); }

  void process() {
    while (!events_.empty()) {
      const auto &event = events_.front();

      this->handle(event);
      events_.pop();
    }
  }

private:
  std::queue<foundation::Event::UniquePtr_t> events_{};
};

NAMESPACE_END(evts)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_EVTS_EVENTBUS_HPP
