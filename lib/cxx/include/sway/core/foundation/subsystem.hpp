#ifndef SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
#define SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP

#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>

namespace sway::core {

class Subsystem : public Object {
  DECLARE_CLASS_METADATA(Subsystem, Object)

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Subsystem() = default;

  explicit Subsystem(typedefs::ContextPtr_t ctx)
      : Object(ctx) {}

  virtual ~Subsystem() = default;

  /** @} */
#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto initialize() -> bool = 0;

  virtual void tick(f32_t dtm) = 0;

  virtual void shutdown() = 0;

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
