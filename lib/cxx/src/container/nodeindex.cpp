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
    .function("getIdxAt", &NodeIndex::getIdxAt)
    .function("toStr", &NodeIndex::toStr);
#endif
EMSCRIPTEN_BINDING_END()

auto NodeIndex::chainToStr(const NodeIndexChainTypedefs::Container_t &chain) -> std::string {
  std::ostringstream oss;
  std::copy(chain.begin(), chain.end() - 1, std::ostream_iterator<int>(oss, ", "));
  oss << "[" << chain.back() << "]";
  return oss.str();
}

auto NodeIndex::getMatchDepth(
    const NodeIndexChainTypedefs::Container_t &lhs, const NodeIndexChainTypedefs::Container_t &rhs) -> int {
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

NodeIndex::NodeIndex(const NodeIndexChainTypedefs::Container_t &data) { setChain(data, NODEIDX_NEGATIVE); }

NodeIndex::NodeIndex(NodeIndex parent, NodeIndexChainTypedefs::Item_t idx) { setChain(parent.getChain(), idx); }

void NodeIndex::setAsRoot() {
  chainLinks_.clear();
  chainLinks_ = NODEIDX_CHAIN_INITIALROOT;
}

void NodeIndex::setChain(const NodeIndexChainTypedefs::Container_t &chain, NodeIndexChainTypedefs::Item_t idx) {
  chainLinks_ = chain;

  if (idx != NODEIDX_NEGATIVE) {
    chainLinks_.push_back(idx);
  }
}

auto NodeIndex::getChain() const -> NodeIndexChainTypedefs::Container_t { return chainLinks_; }

auto NodeIndex::getParent() const -> NodeIndexChainTypedefs::Container_t {
  NodeIndexChainTypedefs::Container_t parent = getChain();
  parent.pop_back();

  return parent;
}

auto NodeIndex::getDepth() const -> int { return (int)chainLinks_.size(); }

auto NodeIndex::getIdxAt(int idx) const -> NodeIndexChainTypedefs::Item_t { return chainLinks_[idx]; }

auto NodeIndex::equal(const NodeIndex &other) -> bool { return chainEqual(other.getChain()); }

auto NodeIndex::chainEqual(const NodeIndexChainTypedefs::Container_t &other) -> bool {
  return chainLinks_.size() == other.size() && std::equal(chainLinks_.begin(), chainLinks_.end(), other.begin());
}

auto NodeIndex::toStr() const -> std::string {
  std::string str = "[";
  for (int i = 0; i < getDepth(); ++i) {
    str += std::to_string(getIdxAt(i));
    if (i < getDepth() - 1) {
      str += ", ";
    }
  }
  str += "]";
  return str;
}

}  // namespace sway::core
