#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

TEST(Event_v2, get_context) {
  auto eventData = EventData();
  auto eventContext = v2::EventContext(eventData, MessageMetadata());
  auto event = v2::Event(eventContext);

  auto ctx = event.getContext();
  auto data = ctx.getEventData();
  auto meta = ctx.getMessageMetadata();

  std::cout << meta.getUniqueId().value() << std::endl;
}
