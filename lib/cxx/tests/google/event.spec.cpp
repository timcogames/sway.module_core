#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

TEST(NewEvent, get_context) {
  auto event = v2::Event(v2::EventContext(EventData(), MessageMetadata()));
  auto eventContext = event.getContext();
}
