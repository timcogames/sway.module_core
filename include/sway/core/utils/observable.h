#ifndef _SWAY_CORE_UTILS_OBSERVABLE_H
#define _SWAY_CORE_UTILS_OBSERVABLE_H

#include <sway/core/utils/observer.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class Observable {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Observable();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Observable();

#pragma endregion

	/**
	 * \brief
	 *    Добавляет нового наблюдателя в список наблюдателей, если его еще нет в списке.
	 * 
	 * \param[in] observer
	 *    Наблюдатель будет добавлен в список наблюдателей.
	 */
	void registerObserver(IObserver * observer);

	/**
	 * \brief
	 *    Удаляет указанного наблюдателя из списка, если он существует.
	 * 
	 * \param[in] observer
	 *    Наблюдатель должен быть исключен из списка наблюдателей.
	 */
	void removeObserver(IObserver * observer);

	/**
	 * \brief
	 *    Уведомляет всех наблюдателей о том, что событие произошло.
	 */
	void notify();

private:
	ObserverArray_t observers_; /*!< Массив наблюдателей, которые слушают этот наблюдаемый объект. */
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_OBSERVABLE_H
