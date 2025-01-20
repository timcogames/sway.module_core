#ifndef SWAY_CORE_CONTAINER_NODEUTIL_HPP
#define SWAY_CORE_CONTAINER_NODEUTIL_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>

namespace sway::core {

struct NodeUtil {
  template <typename TYPE>
  static auto cast(NodeSharedPtr_t ptr) -> std::shared_ptr<TYPE> {
    return std::static_pointer_cast<TYPE>(ptr);
  }

  template <typename TYPE>
  static auto cast(NodeOptionalSharedPtr_t ptr) -> std::shared_ptr<TYPE> {
    return std::static_pointer_cast<TYPE>(ptr.value());
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEUTIL_HPP
