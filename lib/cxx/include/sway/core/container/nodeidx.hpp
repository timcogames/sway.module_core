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

constexpr s32_t NODEIDX_NEGATIVE = (-1);
constexpr s32_t NODEIDX_ROOT = NODEIDX_NEGATIVE;
constexpr s32_t NODEIDX_ROOT_DEPTH = 1;

#define NODEIDX_CHAIN_INITIALROOT std::vector<int>({NODEIDX_ROOT})

class NodeIdx {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  using index_t = s32_t;
  using chain_t = std::vector<NodeIdx::index_t>;

  static auto chainToStr(const NodeIdx::chain_t &chain) -> std::string;

  static auto getMatchDepth(const NodeIdx::chain_t &lhs, const NodeIdx::chain_t &rhs) -> int;

  NodeIdx();

  explicit NodeIdx(const NodeIdx::chain_t &data);

  NodeIdx(NodeIdx parent, NodeIdx::index_t idx);

  ~NodeIdx() = default;

  void setAsRoot();

  void setChain(const NodeIdx::chain_t &chain, NodeIdx::index_t idx);

  [[nodiscard]]
  auto getChain() const -> NodeIdx::chain_t;

  [[nodiscard]]
  auto getParent() const -> NodeIdx::chain_t;

  [[nodiscard]]
  auto getDepth() const -> int;

  [[nodiscard]]
  auto getIdxAt(int idx) const -> NodeIdx::index_t;

  auto equal(const NodeIdx &other) -> bool;

  auto chainEqual(const NodeIdx::chain_t &other) -> bool;

  [[nodiscard]]
  auto toStr() const -> std::string;

private:
  NodeIdx::chain_t chainLinks_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_NODEIDX_HPP
