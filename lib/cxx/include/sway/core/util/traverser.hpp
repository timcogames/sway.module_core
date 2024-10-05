#ifndef SWAY_CORE_UTIL_TRAVERSER_HPP
#define SWAY_CORE_UTIL_TRAVERSER_HPP

#include <sway/core/util/typedefs.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

class Visitable;
class Traverser {
  DECLARE_CLASS_POINTER_ALIASES(Traverser)

public:
#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto visit(VisitablePtr_t node) -> u32_t);

#pragma endregion
};

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_TRAVERSER_HPP
