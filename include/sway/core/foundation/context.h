#ifndef SWAY_CORE_FOUNDATION_CONTEXT_H
#define SWAY_CORE_FOUNDATION_CONTEXT_H

#include <sway/core/foundation/object.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Context();

	/*!
	 * \brief
	 *    Деструктор класса.
	 *
	 *    Освобождает захваченные ресурсы.
	 */
	virtual ~Context();

	/*!
	 * \brief
	 *    Регистрирует объект в контейнере текущего контекста.
	 *
	 * \param[in] object
	 *    Указатель на объект, который следует добавить в контейнер.
	 * 
	 * \sa
	 *    unregisterObject(const std::string &)
	 */
	virtual void registerObject(Object * object);

	/*!
	 * \brief
	 *    Разрегистрирует объект из контейнера текущего контекста.
	 *
	 * \param[in] objectClassName
	 *    Имя класса объекта.
	 * 
	 * \sa
	 *    registerObject(Object *)
	 */
	virtual void unregisterObject(const std::string & objectClassName);

	/*!
	 * \brief
	 *    Получает объект из контейнера текущего контекста.
	 *
	 * \param[in] objectClassName
	 *    Имя класса объекта.
	 */
	virtual Object * getObject(const std::string & objectClassName) const;

	/*!
	 * \brief
	 *    Получает количество зарегистрированных объектов.
	 */
	virtual u32_t getObjectCount() const;

private:
	typedef std::map<std::string, Object *> ObjectMap_t;
	ObjectMap_t _objects; /*!< Контейнер объектов. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_FOUNDATION_CONTEXT_H
