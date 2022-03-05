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
