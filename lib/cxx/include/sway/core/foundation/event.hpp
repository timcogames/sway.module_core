#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

/**
 * \~english @brief Base interface for all event types.
 * \~russian @brief Базовый интерфейс для описания всех типов событий.
 */
class Event {
  DECLARE_SUPERCLASS()
  DECLARE_PTR_ALIASES(Event)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  virtual ~Event() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto id() const -> std::string = 0;

  virtual auto type() const -> u32_t = 0;

  virtual auto data() const -> EventDataTypedefs::Ptr_t = 0;

#pragma endregion

  template <typename RESULT>
  auto getConcreteData() {
    return *static_cast<RESULT *>(data());
  }
};

#include <sway/core/foundation/event_embind.inl>

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_EVENT_HPP
