#ifndef SWAY_CORE_CONTAINERS_TREE_H
#define SWAY_CORE_CONTAINERS_TREE_H

#include <sway/core/containers/treelistener.h>
#include <sway/core/containers/treenodebase.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

typedef std::vector<TreeListener *> TreeListenerVec_t;

class Tree {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Tree();

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Tree();

	TreeNodePtr_t find(const TreeNodeIndex & index);

	/*!
	 * \brief
	 *    Присоединяет нового слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void attachListener(TreeListener * listener);

	/*!
	 * \brief
	 *    Отсоединяет слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void detachListener(TreeListener * listener);

	TreeNodePtr_t getRootNode();

	void setRootNode(TreeNodePtr_t root);

	TreeListenerVec_t getListeners();

private:
	TreeNodePtr_t _root;
	TreeListenerVec_t _listeners;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_CONTAINERS_TREE_H
