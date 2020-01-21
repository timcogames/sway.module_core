#ifndef _SWAY_CORE_CONTAINERS_HIERARCHY_H
#define _SWAY_CORE_CONTAINERS_HIERARCHY_H

#include <sway/core/containers/hierarchynodelistener.h>
#include <sway/core/containers/hierarchynode.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

typedef std::vector<HierarchyNodeListener *> HierarchyNodeListenerVec_t;

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

#pragma endregion

	template<typename TYPE = HierarchyNode>
	TYPE * findNode(const HierarchyNodeIdx & nodeIdx);

	/*!
	 * \brief
	 *    Присоединяет нового слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void addNodeListener(HierarchyNodeListener * listener);

	//void addNodeListener(HierarchyNodeListener * listener, HierarchyNode * node, u32_t flags);

	/*!
	 * \brief
	 *    Отсоединяет слушателя.
	 * 
	 * \param[in] listener
	 *    Указатель на слушателя.
	 */
	void removeNodeListener(HierarchyNodeListener * listener);

	HierarchyNodeListenerVec_t getListeners();

	HierarchyNode * getRootNode();

	void setRootNode(HierarchyNode * root);

private:
	HierarchyNodeListenerVec_t _listeners;
	HierarchyNode * _root;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/containers/hierarchy.inl>

#endif // _SWAY_CORE_CONTAINERS_HIERARCHY_H
