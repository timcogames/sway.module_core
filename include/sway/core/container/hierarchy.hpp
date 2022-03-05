#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>
#include <any>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeData {
    std::vector<NodeIdx::index_t> nodeidx;
    std::string name;
};

#ifdef _EMSCRIPTEN
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy {
  public:
    static void registerEmClass();

    static std::optional<std::shared_ptr<Node>> findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx);

    Hierarchy();
    ~Hierarchy() = default;

    std::shared_ptr<Node> getRootNode();

    void setRootNode(std::shared_ptr<Node> root);

    static int getMatchDepth(NodeIdx::chain_t lhs, const NodeIdx::chain_t &rhs) {
        auto lhs_temp = lhs;
        auto rhs_temp = rhs;
        auto rhs_size = (int)rhs_temp.size();

        int current = -1 /*CHECK_NODE_NA*/;
        for (int i = 0; i < rhs_size; i++) {
            if (lhs.size() <= i || lhs_temp[i] != rhs_temp[i]) {
                return i;
            }

            current = i;
        }

        return current;
    }

    static std::shared_ptr<Node> getMatchNode(std::shared_ptr<Node> node, int depth) {
        while (depth != 0 && node->getNodeIdx().getDepth() != depth) {
            node = node->getParentNode().value();
        }

        return node;
    }

    static std::string getChainStr(NodeIdx::chain_t chain) {
        std::ostringstream oss;
        std::copy(chain.begin(), chain.end() - 1, std::ostream_iterator<int>(oss, ","));
        oss << chain.back();
        return oss.str();
    }

    static void recursiveNodeIdx(std::shared_ptr<Node> node, NodeIdx::chain_t chain) {
        auto currDepth = getMatchDepth(node->getNodeIdx().getChain(), chain);
        auto currChainVal = chain[currDepth];
        auto currNode = getMatchNode(node, currDepth);

        if (currNode->getChildAt(currChainVal).has_value()) {
            currNode = currNode->getChildAt(currChainVal).value();
            if (currDepth != (int)chain.size() - 1) {
                recursiveNodeIdx(currNode, chain);
            }
        } else {
            currNode->addChildNode(std::make_shared<Node>());
            recursiveNodeIdx(currNode, chain);
        }
    }

    static void parse(std::shared_ptr<Node> parent, const NodeDataList &data) {
#ifdef _EMSCRIPTEN
        auto nodeDataList = emscripten::vecFromJSArray<emscripten::val>(data);
#else
        auto nodeDataList = data;
#endif

        for (const auto &node : nodeDataList) {
#ifdef _EMSCRIPTEN
            recursiveNodeIdx(
                parent, emscripten::convertJSArrayToNumberVector<s32_t>(node["nodeidx"].as<emscripten::val>()));
#else
            recursiveNodeIdx(parent, node.nodeidx);
#endif
        }
    }

  private:
    std::shared_ptr<Node> root_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
