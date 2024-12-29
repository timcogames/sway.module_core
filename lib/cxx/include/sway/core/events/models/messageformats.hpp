#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP

#include <sway/numeraltypes.hpp>

namespace sway::core {

enum class MessageFormat : u32_t { NONE = 0, PLAIN_TEXT, JSON, XML, HTML, Latest };

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP
