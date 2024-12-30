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
#pragma region "Ctors/Dtor"

  Subsystem() = default;

  explicit Subsystem(ContextTypedefs::Ptr_t ctx)
      : Object(ctx) {}

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(bool initialize());

  PURE_VIRTUAL(void tick(f32_t dtm));

  PURE_VIRTUAL(void shutdown());

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
