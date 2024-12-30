#ifndef SWAY_CORE_UTIL_TRAVERSER_HPP
#define SWAY_CORE_UTIL_TRAVERSER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/util/_typedefs.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Visitable;
class Traverser {
public:
#pragma region "Pure virtual methods"

  virtual auto visit(VisitableTypedefs::Ptr_t node) -> u32_t = 0;

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_TRAVERSER_HPP
