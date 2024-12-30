#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/events/v2/eventcontext.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * @brief \~english Base interface for all event types. \~russian Базовый интерфейс для описания всех типов событий.
 */
class Event {
  DECLARE_SUPERCLASS()
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  virtual ~Event() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto getId() const -> std::string = 0;

  virtual auto getType() const -> u32_t = 0;

  virtual auto getData() const -> EventDataTypedefs::Ptr_t = 0;

#pragma endregion

  template <typename RESULT>
  auto getConcreteData() const {
    return *static_cast<RESULT *>(getData());
  }
};

#include <sway/core/foundation/event_embind.inl>

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENT_HPP
