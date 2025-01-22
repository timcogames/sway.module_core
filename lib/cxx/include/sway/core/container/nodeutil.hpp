#ifndef SWAY_CORE_CONTAINER_NODEUTIL_HPP
#define SWAY_CORE_CONTAINER_NODEUTIL_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>

namespace sway::core {

struct NodeUtil {
  template <typename TYPE>
  static auto cast(NodeSharedPtr_t ptr) -> std::shared_ptr<TYPE>;

  template <typename TYPE>
  static auto cast(NodeOptionalSharedPtr_t ptr) -> std::shared_ptr<TYPE>;

  static void addChainLinks(NodeSharedPtr_t node, NodeIndex parent);

  static void remChainLinks(NodeSharedPtr_t node, NodeIndex parent);

  static void breakTies(NodeSharedPtr_t node);
};

}  // namespace sway::core

#include <sway/core/container/nodeutil.inl>

#endif  // SWAY_CORE_CONTAINER_NODEUTIL_HPP
