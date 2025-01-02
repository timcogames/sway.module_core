#ifndef SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP
#define SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/messagemetadata.hpp>
#include <sway/core/foundation/eventdata.hpp>

namespace sway::core::v2 {

/**
 * @brief \~english Represents the context in which the event occurred. \~russian Представляет контекст, в котором
 *   произошло событие.
 */
class EventContext {
public:
#pragma region "Ctors/Dtor"

  EventContext(const EventData &data, const MessageMetadata &meta)
      : data_(data)
      , meta_(meta) {}

  ~EventContext() = default;

#pragma endregion

  auto getEventData() -> EventData { return data_; }

  auto getMessageMetadata() -> MessageMetadata { return meta_; }

private:
  EventData data_;
  MessageMetadata meta_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_EVENTCONTEXT_HPP
