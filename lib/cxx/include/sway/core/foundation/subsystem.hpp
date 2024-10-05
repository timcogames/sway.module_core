#ifndef SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
#define SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP

#include <sway/classpointermacros.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

class Subsystem : public Object {
  DECLARE_CLASS_METADATA(Subsystem, Object)
  DECLARE_CLASS_POINTER_ALIASES(Subsystem)

public:
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

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
