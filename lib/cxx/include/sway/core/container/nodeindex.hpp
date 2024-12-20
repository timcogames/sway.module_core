#ifndef SWAY_CORE_CONTAINER_NODEINDEX_HPP
#define SWAY_CORE_CONTAINER_NODEINDEX_HPP

#include <sway/_stdafx.hpp>
#include <sway/containermacros.hpp>
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
  DECLARE_VECTOR(Chain, i32_t)

public:
#pragma region "Static methods"

  static auto chainToStr(const NodeIndex::ChainVec_t &chain) -> std::string;

  static auto getMatchDepth(const NodeIndex::ChainVec_t &lhs, const NodeIndex::ChainVec_t &rhs) -> int;

  /**
   * \~english @brief Returns the last segment in the target node index.
   * @param[in] target Target node index.
   *
   * \~russian @brief Возвращает последний сегмент в индексе целевого узла.
   * @param[in] target Целевой индекс узла.
   *
   * @return NodeIndex::ChainItemIndex_t
   */
  static auto getLastSegment(const NodeIndex &target) -> NodeIndex::ChainItemIndex_t {
    return target.getIdxAt(target.getDepth() - 1);
  }

#pragma endregion

#pragma region "Ctors/Dtor"

  NodeIndex();

  explicit NodeIndex(const NodeIndex::ChainVec_t &data);

  NodeIndex(NodeIndex parent, NodeIndex::ChainItemIndex_t idx);

  ~NodeIndex() = default;

#pragma endregion

  void setAsRoot();

  void setChain(const NodeIndex::ChainVec_t &chain, NodeIndex::ChainItemIndex_t idx);

  [[nodiscard]] auto getChain() const -> NodeIndex::ChainVec_t;

  [[nodiscard]] auto getParent() const -> NodeIndex::ChainVec_t;

  [[nodiscard]] auto getDepth() const -> int;

  [[nodiscard]] auto getIdxAt(int idx) const -> NodeIndex::ChainItemIndex_t;

  auto equal(const NodeIndex &other) -> bool;

  auto chainEqual(const NodeIndex::ChainVec_t &other) -> bool;

  [[nodiscard]] auto toStr() const -> std::string;

private:
  NodeIndex::ChainVec_t chainLinks_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEINDEX_HPP
