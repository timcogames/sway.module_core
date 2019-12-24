#ifndef _SWAY_CORE_CONTAINERS_TREENODEBASE_H
#define _SWAY_CORE_CONTAINERS_TREENODEBASE_H

#include <sway/core/containers/treenodeindex.h>
#include <sway/core/containers/treelistener.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <memory>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class TreeNodeBase;
//typedef std::shared_ptr<TreeNodeBase> TreeNodePtr_t;
typedef TreeNodeBase * TreeNodePtr_t;

class Tree;
class TreeNodeIndex;
class TreeNodeBase {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 * 
	 * \param[in] nodeId
	 *    Идентификатор узла.
	 */
	TreeNodeBase(TreeNodePtr_t parent, const TreeNodeIndex & nodeIndex, const std::string & nodeId);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	virtual ~TreeNodeBase();

	/*!
	 * \brief
	 *    Добавляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	TreeNodeIndex addChild(TreeNodePtr_t child);

	void removeChild(TreeNodePtr_t child);

	/*!
	 * \brief
	 *    Возвращает дочерний узел по его идентификатору.
	 * 
	 * \param[in] nodeId
	 *    Идентификатор узла.
	 */
	TreeNodePtr_t findChild(const std::string & nodeId) const;

	bool hasChild(const std::string & nodeId) const;

	/*!
	 * \brief
	 *    Возвращает дочерний узел по индексу.
	 * 
	 * \param[in] nodeIdx
	 *    Индекс дочерний узла.
	 */
	TreeNodePtr_t getChild(u32_t nodeIdx) const;

	/*!
	 * \brief
	 *    Возвращает дочерние узлы.
	 */
	const std::vector<TreeNodePtr_t> & getChildren() const;

	/*!
	 * \brief
	 *    Возвращает количество дочерних узлов.
	 */
	u32_t getChildCount();

	Tree * getHostTree();

	void setHostTree(Tree * tree);

	/*!
	 * \brief
	 *    Возвращает родительский узел.
	 */
	TreeNodePtr_t getParentNode();

	/*!
	 * \brief
	 *    Устанавливает родительский узел.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 */
	void setParentNode(TreeNodePtr_t parent);

	/*!
	 * \brief
	 *    Возвращает индекс узла.
	 */
	TreeNodeIndex getNodeIndex() const;

	/*!
	 * \brief
	 *    Устанавливает индекс узла.
	 * 
	 * \param[in] nodeIndex
	 *    Индекс узла.
	 */
	void setNodeIndex(const TreeNodeIndex & nodeIndex);

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
	Tree * _tree = nullptr;
	TreeNodePtr_t _parent; /*!< Родительский узел. */
	TreeNodeIndex _nodeIndex;
	std::vector<TreeNodePtr_t> _children; /*!< Последовательный контейнер дочерних узлов. */
	std::string _nodeId; /*!< Уникальный идентификатор узла. */
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_TREENODEBASE_H
