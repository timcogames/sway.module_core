#ifndef _SWAY_CORE_UTILITIES_OBSERVER_H
#define _SWAY_CORE_UTILITIES_OBSERVER_H

#include <sway/namespacemacros.h>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utilities)

typedef std::vector<class IObserver *> ObserverArray_t;
typedef ObserverArray_t::const_iterator ObserverArrayIterator_t;

/*!
 * \brief
 *    Интерфейс наблюдателя.
 */
class IObserver {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IObserver() = default;

#pragma endregion // Constructor / Destructor

#pragma region "Pure virtual methods"

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
    virtual void update() = 0;

#pragma endregion // Pure virtual methods

};

NAMESPACE_END(utilities)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILITIES_OBSERVER_H
