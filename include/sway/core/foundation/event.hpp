#ifndef _SWAY_CORE_FOUNDATION_EVENT_HPP
#define _SWAY_CORE_FOUNDATION_EVENT_HPP

#include <sway/namespacemacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>
#include <string>
#include <memory>
#include <map>
#include <any>

#ifdef _EMSCRIPTEN
	#include <emscripten/emscripten.h>
	#include <emscripten/bind.h>
	#include <emscripten/val.h>

	typedef emscripten::val EventData_t;
#else
	typedef std::map<std::string, std::any> EventData_t;
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class EventWrapper;

/*!
 * \brief
 *    Базовый интерфейс для описания всех типов событий.
 */
class IEvent {
public:
#pragma region "Static methods"

	static void registerEmsClass() {
#ifdef _EMSCRIPTEN
		emscripten::class_<IEvent>("IEvent")
			.allow_subclass<EventWrapper>("EventWrapper")
			.function("getType", &IEvent::getType, emscripten::pure_virtual())
			.function("getUserData", &IEvent::getUserData, emscripten::pure_virtual());
#endif
	}

#pragma endregion

	virtual ~IEvent() = default;

	PURE_VIRTUAL(u32_t getType() const);

	PURE_VIRTUAL(EventData_t getUserData() const);
};

#ifdef _EMSCRIPTEN
class EventWrapper : public emscripten::wrapper<IEvent> {
public:
	EMSCRIPTEN_WRAPPER(EventWrapper);

	OVERRIDE(u32_t getType() const) {
		return call<u32_t>("getType");
	}

	OVERRIDE(EventData_t getUserData() const) {
		return call<EventData_t>("getUserData");
	}
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_FOUNDATION_EVENT_HPP
