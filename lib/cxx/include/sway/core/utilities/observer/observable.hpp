#ifndef SWAY_CORE_UTILITIES_OBSERVABLE_HPP
#define SWAY_CORE_UTILITIES_OBSERVABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/utilities/_typedefs.hpp>
#include <sway/core/utilities/observer/observer.hpp>

namespace sway::core {

class Observable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Observable();

  ~Observable();

  /** @} */
#pragma endregion

  void addObserver(typedefs::ObserverPtr_t obs);

  void removeObserver(typedefs::ObserverPtr_t obs);

  void notify();

private:
  typedefs::ObserverContainer_t observers_; /*!< \~english Array of observers listening to this observable object.
    \~russian Массив наблюдателей, которые слушают этот наблюдаемый объект. */
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_OBSERVABLE_HPP
