#ifndef SWAY_CORE_UTILS_OBSERVABLE_HPP
#define SWAY_CORE_UTILS_OBSERVABLE_HPP

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

  void registerObserver(IObserver *observer);

  void removeObserver(IObserver *observer);

  void notify();

private:
  ObserverArray_t observers_; /*!< Массив наблюдателей, которые слушают этот наблюдаемый объект. */
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
