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
#pragma region "Static methods"

  static auto getMatchDepth(
      const NodeIndexChainTypedefs::Container_t &lhs, const NodeIndexChainTypedefs::Container_t &rhs) -> int;

  /**
   * \~english
   * @brief Returns the last segment in the target node index.
   * @param[in] target Target node index.
   *
   * \~russian
   * @brief Возвращает последний сегмент в индексе целевого узла.
   * @param[in] target Целевой индекс узла.
   *
   * @return NodeIndexChainTypedefs::Item_t
   */
  static auto getLastSegment(const NodeIndex &target) -> NodeIndexChainTypedefs::Item_t {
    return target.getIndexAt(target.getDepth() - 1);
  }

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  NodeIndex();

  explicit NodeIndex(const NodeIndexChainTypedefs::Container_t &data);

  NodeIndex(NodeIndex parent, NodeIndexChainTypedefs::Item_t idx);

  ~NodeIndex() = default;

  /** @} */
#pragma endregion

  void setAsRoot();

  void setChain(const NodeIndexChainTypedefs::Container_t &chain, NodeIndexChainTypedefs::Item_t idx);

  [[nodiscard]] auto getChain() const -> NodeIndexChainTypedefs::Container_t;

  [[nodiscard]] auto getParent() const -> NodeIndexChainTypedefs::Container_t;

  [[nodiscard]] auto getDepth() const -> int;

  [[nodiscard]] auto getIndexAt(int idx) const -> NodeIndexChainTypedefs::Item_t;

  auto equal(const NodeIndex &other) -> bool;

  auto chainEqual(const NodeIndexChainTypedefs::Container_t &other) -> bool;

private:
  NodeIndexChainTypedefs::Container_t chainLinks_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEINDEX_HPP
