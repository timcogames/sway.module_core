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
        .function("getId", &Event::getId, emscripten::pure_virtual())
        .function("getType", &Event::getType, emscripten::pure_virtual())
        .function("getUserData", &Event::getUserData, emscripten::pure_virtual());
#endif
  }

  DFLT_DTOR_VIRTUAL(Event);

  PURE_VIRTUAL(std::string getId() const);

  PURE_VIRTUAL(u32_t getType() const);

  PURE_VIRTUAL(void *getUserData() const);

  template <typename TResult>
  auto getConcreteUserData() {
    return *static_cast<TResult *>(getUserData());
  }
};

#ifdef _EMSCRIPTEN
class EventWrapper : public emscripten::wrapper<Event> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  MTHD_OVERRIDE(std::string getId() const) { return call<u32_t>("getId"); }

  MTHD_OVERRIDE(u32_t getType() const) { return call<u32_t>("getType"); }

  MTHD_OVERRIDE(void *getUserData() const) { return call<void *>("getUserData"); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
