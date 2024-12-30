#ifndef SWAY_CORE_EVENTS_V2_EVENT_HPP
#define SWAY_CORE_EVENTS_V2_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {
namespace v2 {

class Event {
public:
#pragma region "Ctors/Dtor"

  Event(const EventContext &context)
      : context_(context) {}

  ~Event() = default;

#pragma endregion

  auto getContext() -> EventContext { return context_; }

private:
  EventContext context_;
};

}  // namespace v2
}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_V2_EVENT_HPP
