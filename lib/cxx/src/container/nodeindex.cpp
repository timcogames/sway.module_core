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

auto NodeIndex::chainToStr(const NodeIndex::ChainVec_t &chain) -> std::string {
  std::ostringstream oss;
  std::copy(chain.begin(), chain.end() - 1, std::ostream_iterator<int>(oss, ", "));
  oss << "[" << chain.back() << "]";
  return oss.str();
}

auto NodeIndex::getMatchDepth(const NodeIndex::ChainVec_t &lhs, const NodeIndex::ChainVec_t &rhs) -> int {
  auto lhs_temp = lhs;
  auto rhs_temp = rhs;
  auto rhs_size = (int)rhs_temp.size();

  int current = -1 /*CHECK_NODE_NA*/;
  for (int i = 0; i < rhs_size; i++) {
    if ((int)lhs.size() <= i || lhs_temp[i] != rhs_temp[i]) {
      return i;
    }

    current = i;
  }

  return current;
}

NodeIndex::NodeIndex() { setAsRoot(); }

NodeIndex::NodeIndex(const NodeIndex::ChainVec_t &data) { setChain(data, NODEIDX_NEGATIVE); }

NodeIndex::NodeIndex(NodeIndex parent, NodeIndex::ChainItemIndex_t idx) { setChain(parent.getChain(), idx); }

void NodeIndex::setAsRoot() {
  chainLinks_.clear();
  chainLinks_ = NODEIDX_CHAIN_INITIALROOT;
}

void NodeIndex::setChain(const NodeIndex::ChainVec_t &chain, NodeIndex::ChainItemIndex_t idx) {
  chainLinks_ = chain;

  if (idx != NODEIDX_NEGATIVE) {
    chainLinks_.push_back(idx);
  }
}

auto NodeIndex::getChain() const -> NodeIndex::ChainVec_t { return chainLinks_; }

auto NodeIndex::getParent() const -> NodeIndex::ChainVec_t {
  NodeIndex::ChainVec_t parent = getChain();
  parent.pop_back();

  return parent;
}

auto NodeIndex::getDepth() const -> int { return (int)chainLinks_.size(); }

auto NodeIndex::getIdxAt(int idx) const -> NodeIndex::ChainItemIndex_t { return chainLinks_[idx]; }

auto NodeIndex::equal(const NodeIndex &other) -> bool { return chainEqual(other.getChain()); }

auto NodeIndex::chainEqual(const NodeIndex::ChainVec_t &other) -> bool {
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
