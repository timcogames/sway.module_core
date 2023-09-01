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

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_PLATFORM_USE_BINDING
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class EventWrapper;

using EventDataType = void *;

/**
 * @brief Базовый интерфейс для описания всех типов событий.
 */
class Event {
public:
  DECLARE_SUPERCLASS()

  static void registerEmsClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)
    emscripten::class_<Event>("Event")
        .allow_subclass<EventWrapper>("EventWrapper")
        .function("id", &Event::id, emscripten::pure_virtual())
        .function("type", &Event::type, emscripten::pure_virtual())
        .function("data", &Event::data, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
        .function("getSuperclass", &Event::getSuperclass, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
        .function("getClassname", &Event::getClassname, emscripten::pure_virtual());
#endif
  }

  DFLT_DTOR_VIRTUAL(Event);

  // clang-format off
  PURE_VIRTUAL(auto id() const -> std::string);  // clang-format on

  // clang-format off
  PURE_VIRTUAL(auto type() const -> u32_t);  // clang-format on

  // clang-format off
  PURE_VIRTUAL(auto data() const -> EventDataType);  // clang-format on

  template <typename TResult>
  auto getConcreteData() {
    return *static_cast<TResult *>(data());
  }
};

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)
class EventWrapper : public emscripten::wrapper<Event> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  // clang-format off
  MTHD_OVERRIDE(auto id() const -> std::string) {  // clang-format on
    return call<std::string>("id");
  }

  // clang-format off
  MTHD_OVERRIDE(auto type() const -> u32_t) {  // clang-format on
    return call<u32_t>("type");
  }

  // clang-format off
  MTHD_OVERRIDE(auto data() const -> EventDataType) {  // clang-format on
    return call<EventDataType const>("data");
  }

  MTHD_OVERRIDE(const ObjectClassMetadata *getSuperclass() const) {
    return call<const ObjectClassMetadata *const>("getSuperclass");
  }

  MTHD_OVERRIDE(const std::string &getClassname() const) { return call<const std::string &>("getClassname"); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENT_HPP
