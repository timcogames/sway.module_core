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

	HierarchyNode * getRootNode();

	void setRootNode(HierarchyNode * root);

private:
	HierarchyListenerVec_t _listeners;
	HierarchyNode * _root;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/containers/hierarchy.inl>

#endif // _SWAY_CORE_CONTAINERS_HIERARCHY_H
