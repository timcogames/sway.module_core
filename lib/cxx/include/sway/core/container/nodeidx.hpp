#ifndef SWAY_CORE_CONTAINER_NODEIDX_HPP
#define SWAY_CORE_CONTAINER_NODEIDX_HPP

#include <sway/containermacros.hpp>
#include <sway/defines.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <iterator>
#include <string>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

constexpr i32_t NODEIDX_NEGATIVE = GLOB_IDX_INVALID;
constexpr i32_t NODEIDX_ROOT = NODEIDX_NEGATIVE;
constexpr i32_t NODEIDX_ROOT_DEPTH = 1;

#define NODEIDX_CHAIN_INITIALROOT std::vector<i32_t>({NODEIDX_ROOT})

class NodeIdx {
  DECLARE_EMSCRIPTEN_BINDING()
  DECLARE_VECTOR(Chain, i32_t)

public:
#pragma region "Static methods"

  static auto chainToStr(const NodeIdx::ChainVec_t &chain) -> std::string;

  static auto getMatchDepth(const NodeIdx::ChainVec_t &lhs, const NodeIdx::ChainVec_t &rhs) -> int;

#pragma endregion

#pragma region "Ctors/Dtor"

  NodeIdx();

  explicit NodeIdx(const NodeIdx::ChainVec_t &data);

  NodeIdx(NodeIdx parent, NodeIdx::ChainItemIndex_t idx);

  ~NodeIdx() = default;

#pragma endregion

  void setAsRoot();

  void setChain(const NodeIdx::ChainVec_t &chain, NodeIdx::ChainItemIndex_t idx);

  [[nodiscard]]
  auto getChain() const -> NodeIdx::ChainVec_t;

  [[nodiscard]]
  auto getParent() const -> NodeIdx::ChainVec_t;

  [[nodiscard]]
  auto getDepth() const -> int;

  [[nodiscard]]
  auto getIdxAt(int idx) const -> NodeIdx::ChainItemIndex_t;

  auto equal(const NodeIdx &other) -> bool;

  auto chainEqual(const NodeIdx::ChainVec_t &other) -> bool;

  [[nodiscard]]
  auto toStr() const -> std::string;

private:
  NodeIdx::ChainVec_t chainLinks_;
};

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEIDX_HPP
