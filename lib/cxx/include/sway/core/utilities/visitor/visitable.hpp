#ifndef SWAY_CORE_UTILITIES_VISITABLE_HPP
#define SWAY_CORE_UTILITIES_VISITABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/utilities/_typedefs.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Traverser;

/**
 * @brief \~english Interface for visited objects - see Visitor pattern. \~russian Интерфейс для посещаемых объектов -
 * см. паттерн Visitor.
 */
class Visitable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  virtual ~Visitable() = default;

  /** @} */
#pragma endregion

#pragma region "Pure virtual methods"
  /** \~english @name Pure virtual methods */ /** \~russian @name Чисто виртуальные методы */
  /** @{ */

  virtual auto traverse(typedefs::TraverserPtr_t traverser) -> u32_t = 0;

  /** @} */
#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_VISITABLE_HPP
