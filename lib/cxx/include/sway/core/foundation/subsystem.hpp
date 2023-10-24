#ifndef SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
#define SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP

#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Subsystem : public Object {
public:
  DECLARE_CLASS_METADATA(Subsystem, Object)

  Subsystem() = default;

  explicit Subsystem(Context *ctx)
      : Object(ctx) {}

  PURE_VIRTUAL(bool initialize());

  PURE_VIRTUAL(void tick(float timestep));

  PURE_VIRTUAL(void shutdown());
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_SUBSYSTEM_HPP
