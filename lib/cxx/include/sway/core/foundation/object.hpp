#ifndef SWAY_CORE_FOUNDATION_OBJECT_HPP
#define SWAY_CORE_FOUNDATION_OBJECT_HPP

#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

class Context;

class Object {
  DECLARE_SUPERCLASS()
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Object()
      : context_(nullptr) {}

  explicit Object(ContextPtr_t ctx)
      : context_(ctx) {}

#pragma endregion

  auto getContext() -> ContextPtr_t { return context_; }

  template <class TYPE>
  auto getContext() -> TYPE * {
    return static_cast<TYPE *>(context_);
  }

private:
  ContextPtr_t context_;
};

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_OBJECT_HPP
