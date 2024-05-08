#ifndef SWAY_CORE_UTIL_OBSERVABLE_HPP
#define SWAY_CORE_UTIL_OBSERVABLE_HPP

#include <sway/core/util/observer.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(util)

class Observable {
public:
  Observable();

  ~Observable();

  void registerObserver(IObserver *observer);

  void removeObserver(IObserver *observer);

  void notify();

private:
  ObserverArray_t observers_;  // Массив наблюдателей, которые слушают этот наблюдаемый объект.
};

NAMESPACE_END(util)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_UTIL_OBSERVABLE_HPP
