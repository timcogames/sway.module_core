#ifndef _SWAY_CORE_UTILS_OBSERVABLE_HPP
#define _SWAY_CORE_UTILS_OBSERVABLE_HPP

#include <sway/core/utils/observer.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class Observable {
public:
	Observable();

	~Observable();

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

#endif // _SWAY_CORE_UTILS_OBSERVABLE_HPP
