#ifndef _SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
#define _SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP

#include <sway/core/foundation/eventhandler.hpp>
#include <sway/namespacemacros.hpp>
#include <vector>
#include <algorithm> // std::remove_if

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template<class TYPE>
class TEventHandlerImpl : public AEventHandler {
public:
	using HandlerFunction_t = void (TYPE::*)(IEvent *);

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] receiver
	 *    Слушатель события.
	 * 
	 * \param[in] function
	 *    Функция обработчика события.
	 */
	TEventHandlerImpl(TYPE * receiver, HandlerFunction_t function) : AEventHandler(receiver), function_(std::move(function)) { }

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TEventHandlerImpl() = default;

#pragma endregion

	/*!
	 * \brief
	 *    Вызвает функцию обработчика событий.
	 * 
	 * \param[in] eventdata
	 *    Данные события.
	 */
	void invoke(IEvent * event) override {
		TYPE * receiver = static_cast<TYPE *>(receiver_);
		(receiver->*function_)(event);
	}

private:
	HandlerFunction_t function_; /*!< Функцию обработчика событий. */
};

#ifdef _EMSCRIPTEN
class EventHandlerImpl : public AEventHandler {
public:

#pragma region "Static methods"

	static void registerEmsClass() {
		emscripten::class_<EventHandlerImpl, emscripten::base<AEventHandler>>("EventHandlerImpl")
			.constructor<Object *, emscripten::val>()
			.function("invoke", &EventHandlerImpl::invoke, emscripten::allow_raw_pointers());
	}

#pragma endregion

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] receiver
	 *    Слушатель события.
	 * 
	 * \param[in] function
	 *    Функция обработчика события.
	 */
	EventHandlerImpl(Object * receiver, emscripten::val function)
		: AEventHandler(receiver)
		, function_(function) {
		// Empty
	}

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~EventHandlerImpl() = default;

#pragma endregion

	/*!
	 * \brief
	 *    Вызвает функцию обработчика событий.
	 * 
	 * \param[in] eventdata
	 *    Данные события.
	 */
	void invoke(IEvent * event) override {
		if (function_.typeOf().as<std::string>() == "function")
			function_(event);
		else
			EM_ASM(throw "callback is not a function");
	}

private:
	emscripten::val function_; /*!< Функцию обработчика событий. */
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#define EVENT_HANDLER(classname, function) \
	(new core::foundation::TEventHandlerImpl<classname>(this, &classname::function))

#endif // _SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
