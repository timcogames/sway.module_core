#ifndef SWAY_CORE_UTILITIES_OBSERVER_HPP
#define SWAY_CORE_UTILITIES_OBSERVER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/utilities/_typedefs.hpp>
#include <sway/keywords.hpp>

namespace sway::core {

/**
 * @class Observer
 * @brief \~english Observer interface. \~russian Интерфейс наблюдателя.
 */
class Observer {
public:
#pragma region "Ctors/Dtor"

  virtual ~Observer() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual void update() = 0;

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_OBSERVER_HPP
