#ifndef _SWAY_CORE_CONTAINERS_HIERARCHY_H
#define _SWAY_CORE_CONTAINERS_HIERARCHY_H

#include <sway/core/containers/nodeidx.h>
#include <sway/core/containers/node.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class Hierarchy {
public:
#pragma region "Static methods"

	static void registerEmsClass();

	static Node * findNode(Node * root, const NodeIdx & nodeIdx);

#pragma endregion

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Hierarchy();

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Hierarchy();

#pragma endregion

#pragma region "Getters / Setters"

	Node * getRootNode();

	void setRootNode(Node * root);

#pragma endregion

private:
	Node * _root;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHY_H
