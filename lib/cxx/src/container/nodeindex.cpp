#include <sway/core/container/nodeindex.hpp>

#include <sstream>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(NodeIndex)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<NodeIndex>("NodeIndex")
    .constructor<>()
    .constructor<std::vector<i32_t>>()
    .constructor<NodeIndex, i32_t>()
    .function("getChain", &NodeIndex::getChain)
    .function("getParent", &NodeIndex::getParent, emscripten::allow_raw_pointers())
    .function("getDepth", &NodeIndex::getDepth)
    .function("getIndexAt", &NodeIndex::getIndexAt)
    // .function("toStr", &NodeIndex::toStr)
    ;
#endif
EMSCRIPTEN_BINDING_END()

auto NodeIndex::getMatchDepth(const NodeIndexChainContainer_t &lhs, const NodeIndexChainContainer_t &rhs) -> int {
  auto lhsTemp = lhs;
  auto rhsTemp = rhs;
  auto rhsSize = (int)rhsTemp.size();

  int current = -1 /*CHECK_NODE_NA*/;
  for (int i = 0; i < rhsSize; i++) {
    if ((int)lhs.size() <= i || lhsTemp[i] != rhsTemp[i]) {
      return i;
    }

    current = i;
  }

  return current;
}

NodeIndex::NodeIndex() { setAsRoot(); }

NodeIndex::NodeIndex(const NodeIndexChainContainer_t &data) { setChain(data, NODEIDX_NEGATIVE); }

NodeIndex::NodeIndex(NodeIndex parent, NodeIndexChainItem_t idx) { setChain(parent.getChain(), idx); }

void NodeIndex::setAsRoot() {
  chainLinks_.clear();
  chainLinks_ = NODEIDX_CHAIN_INITIALROOT;
}

void NodeIndex::setChain(const NodeIndexChainContainer_t &chain, NodeIndexChainItem_t idx) {
  chainLinks_ = chain;

  if (idx != NODEIDX_NEGATIVE) {
    chainLinks_.push_back(idx);
  }
}

auto NodeIndex::getChain() const -> NodeIndexChainContainer_t { return chainLinks_; }

auto NodeIndex::getParent() const -> NodeIndexChainContainer_t {
  NodeIndexChainContainer_t parent = getChain();
  parent.pop_back();

  return parent;
}

auto NodeIndex::getDepth() const -> int { return (int)chainLinks_.size(); }

auto NodeIndex::getIndexAt(int idx) const -> NodeIndexChainItem_t { return chainLinks_[idx]; }

auto NodeIndex::equal(const NodeIndex &other) -> bool { return chainEqual(other.getChain()); }

auto NodeIndex::chainEqual(const NodeIndexChainContainer_t &other) -> bool {
  return chainLinks_.size() == other.size() && std::equal(chainLinks_.begin(), chainLinks_.end(), other.begin());
}

}  // namespace sway::core
