#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <any>
#include <map>
#include <memory>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

/**
 * @brief Базовый интерфейс для описания всех типов событий.
 */
class Event {
  DECLARE_SUPERCLASS()
  DECLARE_EMSCRIPTEN_BINDING()

public:
  DFLT_DTOR_VIRTUAL(Event);

  // clang-format off
  PURE_VIRTUAL(auto id() const -> std::string);  // clang-format on

  // clang-format off
  PURE_VIRTUAL(auto type() const -> u32_t);  // clang-format on

  // clang-format off
  PURE_VIRTUAL(auto data() const -> EventData *);  // clang-format on

  template <typename TResult>
  auto getConcreteData() {
    return *static_cast<TResult *>(data());
  }
};

#include <sway/core/foundation/event_embind.inl>

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENT_HPP
