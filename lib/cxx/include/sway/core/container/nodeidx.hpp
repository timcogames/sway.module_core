#ifndef SWAY_CORE_CONTAINER_NODEIDX_HPP
#define SWAY_CORE_CONTAINER_NODEIDX_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <iterator>
#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

constexpr i32_t NODEIDX_NEGATIVE = (-1);
constexpr i32_t NODEIDX_ROOT = NODEIDX_NEGATIVE;
constexpr i32_t NODEIDX_ROOT_DEPTH = 1;

#define NODEIDX_CHAIN_INITIALROOT std::vector<int>({NODEIDX_ROOT})

class NodeIdx {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  using Index_t = i32_t;
  using Chain_t = std::vector<NodeIdx::Index_t>;

#pragma region "Static methods"

  static auto chainToStr(const NodeIdx::Chain_t &chain) -> std::string;

  static auto getMatchDepth(const NodeIdx::Chain_t &lhs, const NodeIdx::Chain_t &rhs) -> int;

#pragma endregion

#pragma region "Ctors/Dtor"

  NodeIdx();

  explicit NodeIdx(const NodeIdx::Chain_t &data);

  NodeIdx(NodeIdx parent, NodeIdx::Index_t idx);

  ~NodeIdx() = default;

#pragma endregion

  void setAsRoot();

  void setChain(const NodeIdx::Chain_t &chain, NodeIdx::Index_t idx);

  [[nodiscard]]
  auto getChain() const -> NodeIdx::Chain_t;

  [[nodiscard]]
  auto getParent() const -> NodeIdx::Chain_t;

  [[nodiscard]]
  auto getDepth() const -> int;

  [[nodiscard]]
  auto getIdxAt(int idx) const -> NodeIdx::Index_t;

  auto equal(const NodeIdx &other) -> bool;

  auto chainEqual(const NodeIdx::Chain_t &other) -> bool;

  [[nodiscard]]
  auto toStr() const -> std::string;

private:
  NodeIdx::Chain_t chainLinks_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_NODEIDX_HPP
