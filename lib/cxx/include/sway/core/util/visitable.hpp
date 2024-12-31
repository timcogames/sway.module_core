#ifndef SWAY_CORE_UTIL_VISITABLE_HPP
#define SWAY_CORE_UTIL_VISITABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/util/_typedefs.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Traverser;

class Visitable {
public:
#pragma region "Ctors/Dtor"

  virtual ~Visitable() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto traverse(TraverserTypedefs::Ptr_t traverser) -> u32_t = 0;

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_VISITABLE_HPP
