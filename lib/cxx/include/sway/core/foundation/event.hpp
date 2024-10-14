#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
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
 * @brief Базовый интерфейс для описания всех типов событий.
 */
class Event {
  DECLARE_SUPERCLASS()
  DECLARE_PTR_ALIASES(Event)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  DTOR_VIRTUAL_DEFAULT(Event);

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto id() const -> std::string);

  PURE_VIRTUAL(auto type() const -> u32_t);

  PURE_VIRTUAL(auto data() const -> EventData::Ptr_t);

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
