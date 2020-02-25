#ifndef _SWAY_CORE_FOUNDATION_EVENT_H
#define _SWAY_CORE_FOUNDATION_EVENT_H

#include <sway/namespacemacros.h>
#include <sway/types.h>
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

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IEvent() = default;

#pragma endregion

	/*!
	 * \brief
	 *    Возвращает тип события.
	 */
	virtual u32_t getType() const = 0;

	virtual EventData_t getUserData() const = 0;
};

#ifdef _EMSCRIPTEN
class EventWrapper : public emscripten::wrapper<IEvent> {
public:
	EMSCRIPTEN_WRAPPER(EventWrapper);

	/*!
	 * \brief
	 *    Возвращает тип события.
	 */
	u32_t getType() const override {
		return call<u32_t>("getType");
	}

	EventData_t getUserData() const override {
		return call<EventData_t>("getUserData");
	}
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_FOUNDATION_EVENT_H
