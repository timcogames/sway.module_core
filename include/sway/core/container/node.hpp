#ifndef SWAY_CORE_CONTAINER_NODE_HPP
#define SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/utils/traverser.hpp>
#include <sway/core/utils/visitable.hpp>
#include <sway/keywords.hpp>
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

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct LinearTestData {
    std::vector<s32_t> nodeidx;
    std::string name;
};

#define DECLARE_EVENT(EventId, EventName)                                    \
  public:                                                                    \
    static inline const std::string EventId = #EventName;                    \
    class Evt##EventName final : public foundation::EventBase {              \
      public:                                                                \
        Evt##EventName(u32_t type, EventData_t data)                         \
            : type_(type)                                                    \
            , userdata_(std::move(data)) {}                                  \
        MTHD_OVERRIDE(u32_t getType() const) { return type_; }               \
        MTHD_OVERRIDE(EventData_t getUserData() const) { return userdata_; } \
                                                                             \
      private:                                                               \
        u32_t type_;                                                         \
        EventData_t userdata_;                                               \
    };

class Node : public std::enable_shared_from_this<Node>, public utils::Visitable {
    DECLARE_EVENT(EVT_ADDED, NodeAdded)
    DECLARE_EVENT(EVT_REMOVED, NodeRemoved)

  public:
    static void registerEmClass();

    Node();
    virtual ~Node();

    MTHD_OVERRIDE(u32_t traverse(utils::Traverser *traverser));

    void addChildNode(std::shared_ptr<Node> child);

    void removeChildNode(std::shared_ptr<Node> child);

    std::vector<std::shared_ptr<Node>> getChildNodes();

    std::shared_ptr<Node> getChildNode(const NodeIdx &idx) const;

    std::optional<std::shared_ptr<Node>> getChildAt(int targetIdx) const;

    int getNumOfChildNodes() const;

    void setNodeIdx(NodeIdx::chain_t chain, int idx);

    NodeIdx getNodeIdx();

    void setParentNode(std::weak_ptr<Node> parent);

    std::optional<std::shared_ptr<Node>> getParentNode();

    bool equal(std::shared_ptr<Node> other);

    bool chainEqual(NodeIdx::chain_t other);

    void setAsRoot();

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

    static void addChildNodes(std::shared_ptr<Node> node, int childnodeIdx, NodeIdx::chain_t chain) {
        auto nbrOfChildren = childnodeIdx + 1;

        for (int i = 0; i < nbrOfChildren; i++) {
            if (node->getChildAt(i).has_value()) {
            } else {
                node->addChildNode(std::make_shared<Node>());
            }
        }
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

        // printf("curr idx: %s, depth %i / %i, val: %i\n", currNode->getNodeIdx().toStr().c_str(), currDepth,
        //     (int)chain.size(), currChainVal);

        if (currNode->getChildAt(currChainVal).has_value()) {
            currNode = currNode->getChildAt(currChainVal).value();
            if (currDepth != (int)chain.size() - 1) {
                recursiveNodeIdx(currNode, chain);
            }
        } else {
            currNode->addChildNode(std::make_shared<Node>());
            // printf("new: %s(n%i)\n",
            //     currNode->getChildAt(currNode->getNumOfChildNodes() - 1).value()->getNodeIdx().toStr().c_str(),
            //     currNode->getNumOfChildNodes());

            recursiveNodeIdx(currNode, chain);
        }
    }

    static void parse(std::shared_ptr<Node> parent, const std::vector<LinearTestData> &nodes) {
        for (const auto &node : nodes) {
            // printf("%s", "--------------------\n");
            // printf("TREE NODE: (%s)\n", getChainStr(node.nodeidx).c_str());
            recursiveNodeIdx(parent, node.nodeidx);
            // printf("%s", "--------------------\n");
        }
    }

  protected:
    template <typename T>
    std::shared_ptr<T> sharedFrom(T *ptr) {
        return std::static_pointer_cast<T>(static_cast<Node *>(ptr)->shared_from_this());
    }

  private:
    void recursiveAddChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx);

    void recursiveRemoveChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx);

    NodeIdx idx_;
    std::weak_ptr<Node> parent_;
    std::vector<std::shared_ptr<Node>> children_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
