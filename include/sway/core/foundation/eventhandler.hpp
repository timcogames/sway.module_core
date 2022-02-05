#ifndef _SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
#define _SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>
#include <string>

#ifdef _EMSCRIPTEN
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Object;

/*!
 * \brief
 *    Описывает обработчик для события.
 */
class AEventHandler {
public:
#pragma region "Static methods"

	static void registerEmsClass();

#pragma endregion

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] receiver
	 *    Слушатель события.
	 */
	explicit AEventHandler(Object * receiver);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~AEventHandler() = default;

#pragma endregion

#pragma region "Pure virtual methods"

	/*!
	 * \brief
	 *    Вызвает функцию обработчика событий.
	 * 
	 * \param[in] event
	 *    Данные события.
	 */
	PURE_VIRTUAL(void invoke(IEvent * event));

#pragma endregion

	/*!
	 * \brief
	 *    Возвращает отправителя события.
	 */
	Object * getSender() const;

	/*!
	 * \brief
	 *    Устанавливает отправителя события.
	 * 
	 * \param[in] sender
	 *    Отправитель события.
	 */
	void setSender(Object * sender);

	/*!
	 * \brief
	 *    Возвращает слушателя.
	 */
	Object * getReceiver() const;

	/*!
	 * \brief
	 *    Возвращает название события.
	 */
	std::string getEventName() const {
		return eventname_;
	}

	/*!
	 * \brief
	 *    Устанавливает название события.
	 * 
	 * \param[in] name
	 *    Название события.
	 */
	void setEventName(const std::string & name) {
		eventname_ = name;
	}

protected:
	Object * sender_ = nullptr; /*!< Отправитель события. */
	Object * receiver_; /*!< Слушатель события. */
	std::string uniqueid_; /*!< Уникальный идентификатор,
		который будет связан с функцией обработчика событий. */
	std::string eventname_; /*!< Название события. */
};

#ifdef _EMSCRIPTEN
class AEventHandlerWrapper : public emscripten::wrapper<AEventHandler> {
public:
	EMSCRIPTEN_WRAPPER(AEventHandlerWrapper);
	virtual void invoke(IEvent * event) override {
		return call<void>("invoke", event);
	}
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
