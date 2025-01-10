#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

TEST(Event_v2, ctor_def) {
  auto event = v2::Event(v2::EventContext(), v2::EventData());

  auto eventContext = event.getContext();
  auto metadata = event.getMetadata();
}
