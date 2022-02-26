#include <sway/core/container/nodeidx.hpp>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

void NodeIdx::registerEmClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<NodeIdx>("NodeIdx")
        .constructor<>()
        .constructor<std::vector<s32_t>>()
        .constructor<NodeIdx, s32_t>()
        .function("getChain", &NodeIdx::getChain)
        .function("getParent", &NodeIdx::getParent, emscripten::allow_raw_pointers())
        .function("getDepth", &NodeIdx::getDepth)
        .function("getIdxAt", &NodeIdx::getIdxAt)
        .function("toStr", &NodeIdx::toStr);
#endif
}

NodeIdx::NodeIdx() { setAsRoot(); }

NodeIdx::NodeIdx(const NodeIdx::chain_t &data) { setChain(data, NODEIDX_NEGATIVE); }

NodeIdx::NodeIdx(NodeIdx parent, NodeIdx::index_t idx) { setChain(parent.getChain(), idx); }

void NodeIdx::setAsRoot() {
    chainLinks_.clear();
    chainLinks_ = NODEIDX_CHAIN_INITIALROOT;
}

void NodeIdx::setChain(const NodeIdx::chain_t &chain, NodeIdx::index_t idx) {
    chainLinks_ = chain;

    if (idx != NODEIDX_NEGATIVE) {
        chainLinks_.push_back(idx);
    }
}

NodeIdx::chain_t NodeIdx::getChain() const { return chainLinks_; }

NodeIdx::chain_t NodeIdx::getParent() const {
    NodeIdx::chain_t parent = getChain();
    parent.pop_back();

    return parent;
}

int NodeIdx::getDepth() const { return (int)chainLinks_.size(); }

NodeIdx::index_t NodeIdx::getIdxAt(int idx) const { return chainLinks_[idx]; }

bool NodeIdx::equal(const NodeIdx &other) { return chainEqual(other.getChain()); }

bool NodeIdx::chainEqual(const NodeIdx::chain_t &other) {
    return chainLinks_.size() == other.size() && std::equal(chainLinks_.begin(), chainLinks_.end(), other.begin());
}

std::string NodeIdx::toStr() const {
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

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
