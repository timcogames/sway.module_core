#ifndef SWAY_CORE_UTIL_OBSERVABLE_HPP
#define SWAY_CORE_UTIL_OBSERVABLE_HPP

#include <sway/core/util/observer.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

class Observable {
public:
#pragma region "Ctors/Dtor"

  Observable();

  ~Observable();

#pragma endregion

  void registerObserver(Observer::Ptr_t obs);

  void removeObserver(Observer::Ptr_t obs);

  void notify();

private:
  ObserverArray_t observers_;  // Массив наблюдателей, которые слушают этот наблюдаемый объект.
};

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_OBSERVABLE_HPP
