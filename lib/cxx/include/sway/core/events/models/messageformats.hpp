#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP

#include <sway/numeraltypes.hpp>

namespace sway::core {

enum class MessageFormat : u32_t {
  NONE = 0,  //!< \~english None. \~russian Ничего.
  PLAIN_TEXT,  //!< \~english Plain text. \~russian Обычный текст.
  JSON,  //!< \~english JSON format. \~russian Формат JSON.
  XML,  //!< \~english XML format. \~russian Формат XML.
  HTML,  //!< \~english HTML format. \~russian Формат HTML.
  Latest  //!< \~english Latest element. \~russian Последний элемент.
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEFORMATS_HPP
