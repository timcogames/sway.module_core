#ifndef SWAY_CORE_UTIL_VISITABLE_HPP
#define SWAY_CORE_UTIL_VISITABLE_HPP

#include <sway/core/util/typedefs.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

class Traverser;
class Visitable {
  DECLARE_CLASS_POINTER_ALIASES(Visitable)

public:
#pragma region "Ctors/Dtor"

  DTOR_VIRTUAL_DEFAULT(Visitable);

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto traverse(TraverserPtr_t traverser) -> u32_t);

#pragma endregion
};

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_VISITABLE_HPP
