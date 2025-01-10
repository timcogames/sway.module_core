#ifndef SWAY_CORE_EVENTS_V2_EVENT_HPP
#define SWAY_CORE_EVENTS_V2_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/events/models/messagemetadata.hpp>
#include <sway/core/events/v2/_typedefs.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/core/events/v2/eventdata.hpp>
#include <sway/core/events/v2/eventtarget.hpp>
#include <sway/core/foundation/_typedefs.hpp>
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
  /** \~english @name Constructor & Destructor */ /** \~russian @name Конструктор и Деструктор */
  /** @{ */

  Event(const EventContext &context, const EventData &data, const MessageMetadata &meta = MessageMetadata())
      : context_(context)
      , data_(data)
      , meta_(meta) {}

  ~Event() = default;

  /** @} */
#pragma endregion

  auto getContext() -> EventContext { return context_; }

  auto getEventData() -> EventData { return data_; }

  auto getMetadata() -> MessageMetadata { return meta_; }

  auto getTarget() -> typedefs::EventTargetPtr_t { return target_; }

private:
  EventContext context_;
  EventData data_;
  MessageMetadata meta_;
  typedefs::EventTargetPtr_t target_; /*!< \~english Target object, on which the event has occurred.
    \~russian Целевой объект, на котором произошло событие. */
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENT_HPP
