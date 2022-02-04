#ifndef _SWAY_CORE_CONTAINER_NODEIDX_HPP
#define _SWAY_CORE_CONTAINER_NODEIDX_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

#define NODEIDX_NEGATIVE (-1)
#define NODEIDX_ROOT NODEIDX_NEGATIVE
#define NODEIDX_CHAIN_INITIALROOT std::vector<int>({ NODEIDX_ROOT })

class NodeIdx {
public:
	using index_t = s32_t;
	using chain_t = std::vector<NodeIdx::index_t>;

	static void registerEmsClass();

	NodeIdx();
	NodeIdx(const NodeIdx::chain_t & chain);
	NodeIdx(NodeIdx parent, NodeIdx::index_t idx);

	~NodeIdx() = default;

	void setAsRoot();

	void setChain(const NodeIdx::chain_t & chain, NodeIdx::index_t idx);

	NodeIdx::chain_t getChain() const;

	NodeIdx::chain_t getParent();

	int getDepth() const;

	NodeIdx::index_t getIdxAt(int idx) const;

	bool equals(const NodeIdx & other);

	bool chainEquals(const NodeIdx::chain_t & other);

	std::string toStr();

private:
	NodeIdx::chain_t chainLinks_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINER_NODEIDX_HPP
