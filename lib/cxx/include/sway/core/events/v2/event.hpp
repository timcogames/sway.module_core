#ifndef SWAY_CORE_EVENTS_V2_EVENT_HPP
#define SWAY_CORE_EVENTS_V2_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/events/v2/_typedefs.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/core/events/v2/eventtarget.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core::v2 {

/**
 * @brief \~english Represents the base class for events. \~russian Представляет собой базовый класс для событий.
 */
class Event {
public:
#pragma region "Ctors/Dtor"

  Event(const EventContext &context)
      : context_(context) {}

  ~Event() = default;

#pragma endregion

  auto getContext() -> EventContext { return context_; }

  auto getTarget() -> typedefs::EventTargetPtr_t { return target_; }

private:
  EventContext context_;
  typedefs::EventTargetPtr_t target_; /*!< \~english Target object, on which the event has occurred.
   \~russian Целевой объект, на котором произошло событие. */
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENT_HPP
