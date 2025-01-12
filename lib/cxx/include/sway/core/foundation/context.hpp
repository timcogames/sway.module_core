#ifndef SWAY_CORE_FOUNDATION_CONTEXT_HPP
#define SWAY_CORE_FOUNDATION_CONTEXT_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/subsystem.hpp>
#include <sway/core/foundation/subsystemmanager.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/emscriptenmacros.hpp>

namespace sway::core {

class Context : public SubsystemManager {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Context() = default;

  virtual ~Context() = default;

  /** @} */
#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_CONTEXT_HPP
