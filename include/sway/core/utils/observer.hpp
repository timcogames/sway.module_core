#ifndef _SWAY_CORE_UTILS_OBSERVER_HPP
#define _SWAY_CORE_UTILS_OBSERVER_HPP

#include <sway/namespacemacros.hpp>
#include <sway/keywords.hpp>
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
	virtual ~IObserver() = default;

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
	PURE_VIRTUAL(void update());
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_OBSERVER_HPP
