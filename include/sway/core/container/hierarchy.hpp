#ifndef _SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define _SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

class Hierarchy {
public:
	static void registerEmsClass();

	static std::shared_ptr<Node> findNode(std::shared_ptr<Node> root, const NodeIdx & nodeIdx);

	Hierarchy();

	~Hierarchy() = default;

	std::shared_ptr<Node> getRootNode();

	void setRootNode(std::shared_ptr<Node> root);

private:
	std::shared_ptr<Node> _root;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINER_HIERARCHY_HPP
