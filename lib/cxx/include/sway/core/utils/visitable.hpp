#ifndef SWAY_CORE_UTILS_VISITABLE_HPP
#define SWAY_CORE_UTILS_VISITABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class Traverser;
class Visitable {
public:
  virtual ~Visitable() = default;

  // clang-format off
  PURE_VIRTUAL(auto traverse(Traverser *traverser) -> u32_t);  // clang-format on
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_UTILS_VISITABLE_HPP
