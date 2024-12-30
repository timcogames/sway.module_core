#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEMETADATA_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEMETADATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/_typedefs.hpp>
#include <sway/core/foundation/uniqueable.hpp>
#include <sway/core/util/date/timestamp.hpp>

namespace sway::core {

struct MessageMetadata : public Uniqueable<std::string> {
  std::pair<Timestamp, Timestamp> span;
  u32_t priority;

  MessageMetadata(const std::string &uuid = newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))
      : Uniqueable<std::string>(uuid) {}
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEMETADATA_HPP
