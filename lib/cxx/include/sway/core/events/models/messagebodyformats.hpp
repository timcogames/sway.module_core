#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEBODYFORMATS_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEBODYFORMATS_HPP

#include <sway/common/numeraltypes.hpp>

namespace sway::core {

enum class MessageBodyFormat : u32_t {
  PLAIN_TEXT = 0,  //!< \~english Plain text. \~russian Обычный текст.
  JSON,  //!< \~english JSON format. \~russian Формат JSON.
  XML,  //!< \~english XML format. \~russian Формат XML.
  HTML,  //!< \~english HTML format. \~russian Формат HTML.
  Latest  //!< \~english Latest element. \~russian Последний элемент.
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEBODYFORMATS_HPP
