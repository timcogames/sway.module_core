#ifndef SWAY_CORE_FOUNDATION_OBJECT_HPP
#define SWAY_CORE_FOUNDATION_OBJECT_HPP

#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context;
class Object {
public:
  DECLARE_SUPERCLASS()
  DECLARE_EMSCRIPTEN_BINDING()

  Object()
      : context_(nullptr) {}

  explicit Object(Context *ctx)
      : context_(ctx) {}

  template <class TConcreteContext>
  auto getContext() -> TConcreteContext * {
    return static_cast<TConcreteContext *>(context_);
  }

private:
  Context *context_;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
