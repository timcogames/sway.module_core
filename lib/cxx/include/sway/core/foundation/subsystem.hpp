#ifndef SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
#define SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP

#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Subsystem : public Object {
  DECLARE_CLASS_METADATA(Subsystem, Object)

public:
  using SharedPtr_t = std::shared_ptr<Subsystem>;

#pragma region "Ctors/Dtor"

  Subsystem() = default;

  explicit Subsystem(ContextPtr_t ctx)
      : Object(ctx) {}

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(bool initialize());

  PURE_VIRTUAL(void tick(f32_t dtm));

  PURE_VIRTUAL(void shutdown());

#pragma endregion
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
