#ifndef SWAY_CORE_UTILITIES_TRAVERSER_HPP
#define SWAY_CORE_UTILITIES_TRAVERSER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/utilities/_typedefs.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Visitable;

class Traverser {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Pure virtual methods"
  /** \~english @name Pure virtual methods */ /** \~russian @name Чисто виртуальные методы */
  /** @{ */

  virtual auto visit(typedefs::VisitablePtr_t node) -> u32_t = 0;

  /** @} */
#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_TRAVERSER_HPP
