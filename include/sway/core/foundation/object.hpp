#ifndef _SWAY_CORE_FOUNDATION_OBJECT_H
#define _SWAY_CORE_FOUNDATION_OBJECT_H

#include <sway/core/foundation/event.h>
#include <sway/core/foundation/eventhandler.h>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>
#include <vector>
#include <algorithm> // std::remove_if

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context;
class Object {
public:

#pragma region "Static methods"

	static void registerEmsClass();

#pragma endregion

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] context
	 *    Контекст.
	 */
	Object(Context * context);

	/*!
	 * \brief
	 *    Деструктор класса.
	 *    Освобождает захваченные ресурсы.
	 */
	~Object();

	void subscribe(Object * sender, const std::string & eventname, AEventHandler * handler);

	void unsubscribe(const std::string & eventname);

	/*!
	 * \brief
	 *    Испускает построенное событие.
	 * 
	 * \param[in] eventname
	 *    Имя события.
	 * 
	 * \param[in] event
	 *    Данные события.
	 */
	void emit(const std::string & eventname, IEvent * event);

	AEventHandler * findEventHandler(const std::string & eventname);

	/*!
	 * \brief
	 *    Возвращает идентификатор объекта.
	 */
	std::string getUid() const;

	/*!
	 * \brief
	 *    Устанавливает идентификатор для текущего объекта.
	 * 
	 * \param[in] id
	 *    Уникальный идентификатор.
	 */
	void setUid(const std::string & id);

protected:
	Context * context_; /*!< Контекст. */
	std::vector<AEventHandler *> eventHandlers_; /*!< Обработчики событий. */
	std::string uniqueid_; /*!< Уникальный идентификатор текущего объекта. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_FOUNDATION_OBJECT_H
