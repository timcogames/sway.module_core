#ifndef SWAY_CORE_CONTAINER_NODEIDX_HPP
#define SWAY_CORE_CONTAINER_NODEIDX_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

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
  public:
    using index_t = s32_t;
    using chain_t = std::vector<NodeIdx::index_t>;

    static void registerEmClass();
    static std::string toStr(const NodeIdx::chain_t &chain);
    static int getMatchDepth(const NodeIdx::chain_t &lhs, const NodeIdx::chain_t &rhs);

    NodeIdx();
    explicit NodeIdx(const NodeIdx::chain_t &data);
    explicit NodeIdx(NodeIdx parent, NodeIdx::index_t idx);
    ~NodeIdx() = default;

    void setAsRoot();

    void setChain(const NodeIdx::chain_t &chain, NodeIdx::index_t idx);

    [[nodiscard]] NodeIdx::chain_t getChain() const;

    [[nodiscard]] NodeIdx::chain_t getParent() const;

    [[nodiscard]] int getDepth() const;

    [[nodiscard]] NodeIdx::index_t getIdxAt(int idx) const;

    bool equal(const NodeIdx &other);

    bool chainEqual(const NodeIdx::chain_t &other);

    [[nodiscard]] std::string toStr() const;

  private:
    NodeIdx::chain_t chainLinks_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
