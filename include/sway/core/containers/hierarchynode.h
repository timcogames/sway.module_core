#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H

#include <sway/core/containers/hierarchytraversalactions.h>
#include <sway/core/containers/hierarchytraverser.h>
#include <sway/core/containers/hierarchynodeidx.h>
#include <sway/core/containers/hierarchynodelistener.h>
#include <sway/core/utilities/visitable.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <memory>
#include <vector>
#include <functional>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class Hierarchy;
class HierarchyNodeIdx;
class HierarchyNode {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 * 
	 * \param[in] nodeIdx
	 *    Индекс узела.
	 * 
	 * \param[in] nodeUid
	 *    Идентификатор узла.
	 */
	HierarchyNode(HierarchyNode * parent,
		const HierarchyNodeIdx & nodeIdx, const std::string & nodeUid);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~HierarchyNode() = default;

#pragma endregion

	TraversalAction_t traverse(IHierarchyTraverser * traverser);

	/*!
	 * \brief
	 *    Добавляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	HierarchyNodeIdx addChild(HierarchyNode * child);

	/*!
	 * \brief
	 *    Удаляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	void removeChild(HierarchyNode * child);

	/*!
	 * \brief
	 *    Возвращает дочерний узел по его идентификатору.
	 * 
	 * \param[in] nodeUid
	 *    Идентификатор узла.
	 * 
	 * \sa
	 *    getChildAt(u32_t targetIdx)
	 */
	template<typename TYPE = HierarchyNode>
	TYPE * getChild(const std::string & nodeUid) const;

	/*!
	 * \brief
	 *    Возвращает дочерний узел по индексу.
	 * 
	 * \param[in] targetIdx
	 *    Индекс дочерний узла.
	 * 
	 * \sa
	 *    getChild(const std::string & nodeUid)
	 */
	template<typename TYPE = HierarchyNode>
	TYPE * getChildAt(u32_t targetIdx) const;

	bool hasChild(const std::string & nodeUid) const;

	/*!
	 * \brief
	 *    Возвращает дочерние узлы.
	 */
	const std::vector<HierarchyNode *> & getChildren() const;

	/*!
	 * \brief
	 *    Возвращает количество дочерних узлов.
	 */
	u32_t getChildCount();

	Hierarchy * getHostTree();

	void setHostTree(Hierarchy * tree);

	/*!
	 * \brief
	 *    Возвращает родительский узел.
	 */
	HierarchyNode * getParentNode();

	/*!
	 * \brief
	 *    Устанавливает родительский узел.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 */
	void setParentNode(HierarchyNode * parent);

	bool hasParentNode() const;

	/*!
	 * \brief
	 *    Возвращает индекс узла.
	 */
	HierarchyNodeIdx getNodeIdx() const;

	/*!
	 * \brief
	 *    Устанавливает индекс узла.
	 * 
	 * \param[in] nodeIdx
	 *    Индекс узла.
	 */
	void setNodeIdx(const HierarchyNodeIdx & nodeIdx);

	/*!
	 * \brief
	 *    Возвращает идентификатор узла.
	 */
	std::string getNodeUid() const;

	/*!
	 * \brief
	 *    Устанавливает идентификатор узла.
	 * 
	 * \param[in] nodeUid
	 *    Идентификатор узла.
	 */
	void setNodeUid(const std::string & nodeUid);

private:
	Hierarchy * _tree = nullptr;
	HierarchyNode * _parent; /*!< Родительский узел. */
	std::vector<HierarchyNode *> _children; /*!< Последовательный контейнер дочерних узлов. */
	HierarchyNodeIdx _nodeIdx;
	std::string _nodeUid; /*!< Уникальный идентификатор узла. */
};

struct HierarchyNodeEventData {
	HierarchyNodeListener * listener;
	HierarchyNode * node;
	u32_t flags;

	HierarchyNodeEventData(HierarchyNodeListener * listener, HierarchyNode * node, u32_t flags)
		: listener(listener)
		, node(node)
		, flags(flags) {
		// Empty
	}
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/containers/hierarchynode.inl>

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H
