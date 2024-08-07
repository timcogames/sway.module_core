#ifndef SWAY_CORE_UTIL_VISITABLE_HPP
#define SWAY_CORE_UTIL_VISITABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(util)

class Traverser;
class Visitable {
public:
  using Ptr_t = Visitable *;

#pragma region "Ctors/Dtor"

  virtual ~Visitable() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto traverse(Traverser *traverser) -> u32_t);

#pragma endregion
};

NAMESPACE_END(util)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_UTIL_VISITABLE_HPP
