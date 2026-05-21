#ifndef SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP
#define SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventlistener.hpp>
#include <sway/core/events/v2/eventlistenerlist.hpp>

namespace sway::core::v2 {

class EventService {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EventService() {}

  ~EventService() = default;

  /** @} */
#pragma endregion

  void addEventListener(EventListener listener);

  // on_message = new Delegate<void, lpstr_t>(this, &Manager::handleResponse);
  // ws.addEventListener("on_message", on_message);
  //
  // if (on_message != nullptr) {
  //   (*on_message)(packet);
  // }
  void addEventListener(lpstr_t type, DelegatePtr_t<void, lpstr_t> callback) {
    // if (strcmp(type, "on_message") == 0) {
    //   onMessageCallback_ = callback;
    // } else if (strcmp(type, "on_close") == 0) {
    //   onCloseCallback_ = callback;
    // }
  }

  void removeEventListener(EventListener listener);

  void fireEvent(EventUniquePtr_t &&event) {}

private:
  EventListenerList listeners_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTSERVICE_HPP
