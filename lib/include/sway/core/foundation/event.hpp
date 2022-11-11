#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <any>
#include <map>
#include <memory>
#include <string>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class EventWrapper;

struct EventUserData {
  PURE_VIRTUAL(std::string serialize() const);
};

/*!
 * \brief Базовый интерфейс для описания всех типов событий.
 */
class Event {
public:
  DECLARE_SUPERCLASS()

  static void registerEmsClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<Event>("Event")
        .allow_subclass<EventWrapper>("EventWrapper")
        .function("id", &Event::id, emscripten::pure_virtual())
        .function("type", &Event::type, emscripten::pure_virtual())
        .function("data", &Event::data, emscripten::pure_virtual());
#endif
  }

  DFLT_DTOR_VIRTUAL(Event);

  PURE_VIRTUAL(std::string id() const);

  PURE_VIRTUAL(u32_t type() const);

  PURE_VIRTUAL(void *data() const);

  template <typename TResult>
  auto getConcreteData() {
    return *static_cast<TResult *>(data());
  }
};

#ifdef _EMSCRIPTEN
class EventWrapper : public emscripten::wrapper<Event> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  MTHD_OVERRIDE(std::string id() const) { return call<u32_t>("id"); }

  MTHD_OVERRIDE(u32_t type() const) { return call<u32_t>("type"); }

  MTHD_OVERRIDE(void *data() const) { return call<void *>("data"); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
