#ifndef SWAY_CORE_UTIL_OBSERVABLE_HPP
#define SWAY_CORE_UTIL_OBSERVABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/util/_typedefs.hpp>
#include <sway/core/util/observer.hpp>

namespace sway::core {

class Observable {
public:
#pragma region "Ctors/Dtor"

  Observable();

  ~Observable();

#pragma endregion

  void addObserver(ObserverTypedefs::Ptr_t obs);

  void removeObserver(ObserverTypedefs::Ptr_t obs);

  void notify();

private:
  ObserverTypedefs::Container_t observers_; /*!< \~english Array of observers listening to this observable object.
    \~russian Массив наблюдателей, которые слушают этот наблюдаемый объект. */
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_OBSERVABLE_HPP
