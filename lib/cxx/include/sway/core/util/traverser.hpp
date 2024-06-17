#ifndef SWAY_CORE_UTIL_TRAVERSER_HPP
#define SWAY_CORE_UTIL_TRAVERSER_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(util)

class Visitable;
class Traverser {
public:
  enum class Action : u32_t {
    CONTINUE,  // Продолжать обходить.
    PRUNE,  // Не навещай дочерние узлы.
    ABORT  // Прервать обход.
  };

  // clang-format off
  PURE_VIRTUAL(auto visit(Visitable *node) -> u32_t);  // clang-format on
};

NAMESPACE_END(util)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_UTIL_TRAVERSER_HPP