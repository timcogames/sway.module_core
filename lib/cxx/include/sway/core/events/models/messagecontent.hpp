#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGECONTENT_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGECONTENT_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/models/_typedefs.hpp>
#include <sway/core/events/models/messagebody.hpp>
#include <sway/core/events/models/messageformats.hpp>
#include <sway/core/foundation/uniqueable.hpp>
#include <sway/core/misc/dictionary.hpp>
#include <sway/core/util/date/timestamp.hpp>

namespace sway::core {

/**
 * \~english @brief Describes the content of a message.
 * \~russian @brief Описывает содержимое сообщения.
 */
struct MessageContent {
  MessageFormat format;
  MessageUserData_t userdata;
  MessageBodyTypedefs::SharedPtr_t body;

  MessageContent()
      : format(MessageFormat::PLAIN_TEXT) {}
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGECONTENT_HPP
