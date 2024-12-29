#ifndef SWAY_CORE_EVENTS_MODELS_IO_SERIALIZER_HPP
#define SWAY_CORE_EVENTS_MODELS_IO_SERIALIZER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/_typedefs.hpp>

namespace sway::core {

struct Serializer {
  virtual auto serialize() const -> std::string = 0;
};

struct Deserializer {
  virtual auto deserialize(const std::string &data) -> DeserializerTypedefs::OutResult_t = 0;
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_IO_SERIALIZER_HPP
