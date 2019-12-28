#ifndef _SWAY_CORE_CONTAINERS_HIERARCHY_H
#define _SWAY_CORE_CONTAINERS_HIERARCHY_H

#include <sway/core/containers/hierarchylistener.h>
#include <sway/core/containers/hierarchynode.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

typedef std::vector<HierarchyListener *> HierarchyListenerVec_t;

class Hierarchy {
public:

#pragma region "Constructor / Destructor"

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

#pragma endregion // Constructor / Destructor

	HierarchyNodePtr_t find(const HierarchyNodeIndex & index);

	/*!
	 * \brief
	 *    Присоединяет нового слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void attachListener(HierarchyListener * listener);

	/*!
	 * \brief
	 *    Отсоединяет слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void detachListener(HierarchyListener * listener);

	HierarchyListenerVec_t getListeners();

	HierarchyNodePtr_t getRootNode();

	void setRootNode(HierarchyNodePtr_t root);

private:
	HierarchyListenerVec_t _listeners;
	HierarchyNodePtr_t _root;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHY_H
