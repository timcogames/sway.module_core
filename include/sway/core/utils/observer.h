#ifndef _SWAY_CORE_UTILS_OBSERVER_H
#define _SWAY_CORE_UTILS_OBSERVER_H

#include <sway/namespacemacros.h>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

typedef std::vector<class IObserver *> ObserverArray_t;
typedef ObserverArray_t::const_iterator ObserverArrayIterator_t;

/*!
 * \brief
 *    Интерфейс наблюдателя.
 */
class IObserver {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IObserver() = default;

#pragma endregion

#pragma region "Pure virtual methods"

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
	virtual void update() = 0;

#pragma endregion
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_OBSERVER_H
