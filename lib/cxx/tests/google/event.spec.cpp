#include <sway/core/events/models/messagecontent.hpp>
#include <sway/core/events/v2/event.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

TEST(Event_v2, ctor_def) {
  auto event = v2::Event(v2::EventContext(), new v2::EventData<MessageContent>());

  auto eventContext = event.getContext();
  auto metadata = event.getMetadata();
}
