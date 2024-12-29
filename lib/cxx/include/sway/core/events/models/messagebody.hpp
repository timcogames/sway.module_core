#ifndef SWAY_CORE_EVENTS_MODELS_MESSAGEBODY_HPP
#define SWAY_CORE_EVENTS_MODELS_MESSAGEBODY_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

/**
 * \~english @brief Data associated with the content of a message, providing support for various transformations and
 *   integration with different serializers and deserializers.
 * \~russian @brief Данные, связанные с содержимым сообщения, обеспечивающие поддержку различных преобразований и
 *   интеграцию с различными сериализаторами и десериализаторами.
 */
struct MessageBody {
  std::string data;
};

}  // namespace sway::core

#endif  // SWAY_CORE_EVENTS_MODELS_MESSAGEBODY_HPP
