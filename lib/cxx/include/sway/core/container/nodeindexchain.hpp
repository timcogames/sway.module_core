#ifndef SWAY_CORE_CONTAINER_NODEINDEXCHAIN_HPP
#define SWAY_CORE_CONTAINER_NODEINDEXCHAIN_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/defines.hpp>

namespace sway::core {

struct NodeIndexChain {
  /**
   * \~english @brief Returns the index of the previous node in the chain.
   * @param[in] target Target node index.
   *
   * \~russian @brief Возвращает индекс предыдущего узла в цепочке.
   * @param[in] target Целевой индекс узла.
   *
   * @return NodeIndexTypedefs::Optional_t
   */
  static auto getPrevItem(const NodeIndex &target) -> NodeIndexTypedefs::Optional_t {
    if (auto lastSegment = NodeIndex::getLastSegment(target); lastSegment > GLOB_NULL) {
      auto prev = NodeIndex();
      prev.setChain(target.getParent(), lastSegment - 1);
      return prev;
    }

    return std::nullopt;
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEINDEXCHAIN_HPP
