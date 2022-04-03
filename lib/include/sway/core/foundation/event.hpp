#ifndef SWAY_CORE_FOUNDATION_EVENT_HPP
#define SWAY_CORE_FOUNDATION_EVENT_HPP

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

using EventData_t = emscripten::val;
#else
using EventData_t = std::map<std::string, std::any>;
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class EventWrapper;

/*!
 * \brief Базовый интерфейс для описания всех типов событий.
 */
class EventBase {
public:
  static void registerEmsClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<EventBase>("EventBase")
        .allow_subclass<EventWrapper>("EventWrapper")
        .function("getType", &EventBase::getType, emscripten::pure_virtual())
        .function("getUserData", &EventBase::getUserData, emscripten::pure_virtual());
#endif
  }

  virtual ~EventBase() = default;

  PURE_VIRTUAL(u32_t getType() const);

  PURE_VIRTUAL(EventData_t getUserData() const);
};

#ifdef _EMSCRIPTEN
class EventWrapper : public emscripten::wrapper<EventBase> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  MTHD_OVERRIDE(u32_t getType() const) { return call<u32_t>("getType"); }

  MTHD_OVERRIDE(EventData_t getUserData() const) { return call<EventData_t>("getUserData"); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
