#ifndef SWAY_CORE_EVENTS_MODELS_IO_SERIALIZATION_DESERIALIZER_HPP
#define SWAY_CORE_EVENTS_MODELS_IO_SERIALIZATION_DESERIALIZER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/_typedefs.hpp>

namespace sway::core {

struct Deserializer {
#pragma region "Define aliases"

  using SharedPtr_t = DeserializerSharedPtr_t;
  using OutResult_t = DeserializerOutResult_t;

#pragma endregion

  virtual auto deserialize(const std::string &data) -> DeserializerOutResult_t = 0;
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_IO_SERIALIZATION_DESERIALIZER_HPP
