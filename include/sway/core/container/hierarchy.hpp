#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <optional>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

class Hierarchy {
  public:
    static void registerEmClass();

    static std::optional<std::shared_ptr<Node>> findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx);

    Hierarchy();
    ~Hierarchy() = default;

    std::shared_ptr<Node> getRootNode();

    void setRootNode(std::shared_ptr<Node> root);

  private:
    std::shared_ptr<Node> root_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
