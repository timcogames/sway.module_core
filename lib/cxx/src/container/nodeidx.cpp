#include <sway/core/container/nodeidx.hpp>

#include <sstream>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

EMSCRIPTEN_BINDING_BEGIN(NodeIdx)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<NodeIdx>("NodeIdx")
    .constructor<>()
    .constructor<std::vector<i32_t>>()
    .constructor<NodeIdx, i32_t>()
    .function("getChain", &NodeIdx::getChain)
    .function("getParent", &NodeIdx::getParent, emscripten::allow_raw_pointers())
    .function("getDepth", &NodeIdx::getDepth)
    .function("getIdxAt", &NodeIdx::getIdxAt)
    .function("toStr", &NodeIdx::toStr);
#endif
EMSCRIPTEN_BINDING_END()

auto NodeIdx::chainToStr(const NodeIdx::ChainVec_t &chain) -> std::string {
  std::ostringstream oss;
  std::copy(chain.begin(), chain.end() - 1, std::ostream_iterator<int>(oss, ", "));
  oss << "[" << chain.back() << "]";
  return oss.str();
}

auto NodeIdx::getMatchDepth(const NodeIdx::ChainVec_t &lhs, const NodeIdx::ChainVec_t &rhs) -> int {
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

NodeIdx::NodeIdx() { setAsRoot(); }

NodeIdx::NodeIdx(const NodeIdx::ChainVec_t &data) { setChain(data, NODEIDX_NEGATIVE); }

NodeIdx::NodeIdx(NodeIdx parent, NodeIdx::ChainItemIndex_t idx) { setChain(parent.getChain(), idx); }

void NodeIdx::setAsRoot() {
  chainLinks_.clear();
  chainLinks_ = NODEIDX_CHAIN_INITIALROOT;
}

void NodeIdx::setChain(const NodeIdx::ChainVec_t &chain, NodeIdx::ChainItemIndex_t idx) {
  chainLinks_ = chain;

  if (idx != NODEIDX_NEGATIVE) {
    chainLinks_.push_back(idx);
  }
}

auto NodeIdx::getChain() const -> NodeIdx::ChainVec_t { return chainLinks_; }

auto NodeIdx::getParent() const -> NodeIdx::ChainVec_t {
  NodeIdx::ChainVec_t parent = getChain();
  parent.pop_back();

  return parent;
}

auto NodeIdx::getDepth() const -> int { return (int)chainLinks_.size(); }

auto NodeIdx::getIdxAt(int idx) const -> NodeIdx::ChainItemIndex_t { return chainLinks_[idx]; }

auto NodeIdx::equal(const NodeIdx &other) -> bool { return chainEqual(other.getChain()); }

auto NodeIdx::chainEqual(const NodeIdx::ChainVec_t &other) -> bool {
  return chainLinks_.size() == other.size() && std::equal(chainLinks_.begin(), chainLinks_.end(), other.begin());
}

auto NodeIdx::toStr() const -> std::string {
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

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway
