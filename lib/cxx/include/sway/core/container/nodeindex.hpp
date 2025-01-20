#ifndef SWAY_CORE_CONTAINER_NODEINDEX_HPP
#define SWAY_CORE_CONTAINER_NODEINDEX_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/defines.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

constexpr i32_t NODEIDX_NEGATIVE = GLOB_IDX_INVALID;
constexpr i32_t NODEIDX_ROOT = NODEIDX_NEGATIVE;
constexpr i32_t NODEIDX_ROOT_DEPTH = 1;

#define NODEIDX_CHAIN_INITIALROOT std::vector<i32_t>({NODEIDX_ROOT})

class NodeIndex {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Define aliases"

  using Optional_t = NodeIndexOptional_t;

#pragma endregion

#pragma region "Static methods"

  static auto getMatchDepth(const NodeIndexChainContainer_t &lhs, const NodeIndexChainContainer_t &rhs) -> int;

  /**
   * \~english
   * @brief Returns the last segment in the target node index.
   * @param[in] target Target node index.
   *
   * \~russian
   * @brief Возвращает последний сегмент в индексе целевого узла.
   * @param[in] target Целевой индекс узла.
   *
   * @return NodeIndexChainItem_t
   */
  static auto getLastSegment(const NodeIndex &target) -> NodeIndexChainItem_t {
    return target.getIndexAt(target.getDepth() - 1);
  }

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  NodeIndex();

  explicit NodeIndex(const NodeIndexChainContainer_t &data);

  NodeIndex(NodeIndex parent, NodeIndexChainItem_t idx);

  ~NodeIndex() = default;

  /** @} */
#pragma endregion

  void setAsRoot();

  void setChain(const NodeIndexChainContainer_t &chain, NodeIndexChainItem_t idx);

  [[nodiscard]] auto getChain() const -> NodeIndexChainContainer_t;

  [[nodiscard]] auto getParent() const -> NodeIndexChainContainer_t;

  [[nodiscard]] auto getDepth() const -> int;

  [[nodiscard]] auto getIndexAt(int idx) const -> NodeIndexChainItem_t;

  auto equal(const NodeIndex &other) -> bool;

  auto chainEqual(const NodeIndexChainContainer_t &other) -> bool;

private:
  NodeIndexChainContainer_t chainLinks_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEINDEX_HPP
