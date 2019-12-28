#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H

#include <sway/core/containers/hierarchynodeindex.h>
#include <sway/core/containers/hierarchylistener.h>
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

class HierarchyNode;
//typedef std::shared_ptr<HierarchyNode> HierarchyNodePtr_t;
typedef HierarchyNode * HierarchyNodePtr_t;

class Hierarchy;
class HierarchyNodeIndex;
class HierarchyNode
	: public virtual utilities::IVisitable {

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
	 * \param[in] nodeIndex
	 *    Индекс узела.
	 * 
	 * \param[in] nodeId
	 *    Идентификатор узла.
	 */
	HierarchyNode(HierarchyNodePtr_t parent, const HierarchyNodeIndex & nodeIndex, const std::string & nodeId);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	virtual ~HierarchyNode();

#pragma endregion // Constructor / Destructor

#pragma region "IVisitable implementation"

	virtual void accept(utilities::Visitor * visitor) override;

#pragma endregion // IVisitable implementation

	/*!
	 * \brief
	 *    Добавляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	HierarchyNodeIndex addChild(HierarchyNodePtr_t child);

	HierarchyNodeIndex add(HierarchyNodePtr_t child, std::function<void (const HierarchyNodeIndex &)> handleNodeAdded);

	void removeChild(HierarchyNodePtr_t child);

	/*!
	 * \brief
	 *    Возвращает дочерний узел по его идентификатору.
	 * 
	 * \param[in] nodeId
	 *    Идентификатор узла.
	 */
	HierarchyNodePtr_t findChild(const std::string & nodeId) const;

	bool hasChild(const std::string & nodeId) const;

	/*!
	 * \brief
	 *    Возвращает дочерний узел по индексу.
	 * 
	 * \param[in] nodeIndex
	 *    Индекс дочерний узла.
	 */
	HierarchyNodePtr_t getChild(u32_t nodeIndex) const;

	template<typename TYPE>
	TYPE getChildAt(u32_t nodeIndex) const {
		return static_cast<TYPE> (getChild(nodeIndex));
	}

	/*!
	 * \brief
	 *    Возвращает дочерние узлы.
	 */
	const std::vector<HierarchyNodePtr_t> & getChildren() const;

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
	HierarchyNodePtr_t getParentNode();

	/*!
	 * \brief
	 *    Устанавливает родительский узел.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 */
	void setParentNode(HierarchyNodePtr_t parent);

	/*!
	 * \brief
	 *    Возвращает индекс узла.
	 */
	HierarchyNodeIndex getNodeIndex() const;

	/*!
	 * \brief
	 *    Устанавливает индекс узла.
	 * 
	 * \param[in] nodeIndex
	 *    Индекс узла.
	 */
	void setNodeIndex(const HierarchyNodeIndex & nodeIndex);

	/*!
	 * \brief
	 *    Возвращает идентификатор узла.
	 */
	std::string getNodeId() const;

	/*!
	 * \brief
	 *    Устанавливает идентификатор узла.
	 * 
	 * \param[in] parent
	 *    Идентификатор узла.
	 */
	void setNodeId(const std::string & nodeId);

private:
	Hierarchy * _tree = nullptr;
	HierarchyNodePtr_t _parent; /*!< Родительский узел. */
	HierarchyNodeIndex _nodeIndex;
	std::vector<HierarchyNodePtr_t> _children; /*!< Последовательный контейнер дочерних узлов. */
	std::string _nodeId; /*!< Уникальный идентификатор узла. */
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYNODE_H
