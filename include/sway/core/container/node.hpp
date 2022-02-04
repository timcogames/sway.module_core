#ifndef _SWAY_CORE_CONTAINER_NODE_HPP
#define _SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/utils/traverser.hpp>
#include <sway/core/utils/visitable.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <memory>
#include <vector>
#include <any>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

#define DECLARE_EVENT(EventId, EventName) \
	public: \
		inline static const std::string EventId = #EventName; \
		class Evt##EventName: public foundation::IEvent { \
		public: \
			Evt##EventName(u32_t type, EventData_t data) \
				: type_(type), userdata_(std::move(data)) { } \
			virtual ~Evt##EventName() = default; \
			u32_t getType() const override { return type_; } \
			EventData_t getUserData() const override { return userdata_; } \
		private: \
			u32_t type_; \
			EventData_t userdata_; \
		};

typedef std::vector<class Node *> NodeVec_t;

class Node : public foundation::Object, public utils::Visitable {

	DECLARE_EVENT(EVT_ADDED, NodeAdded)
	DECLARE_EVENT(EVT_REMOVED, NodeRemoved)
public:
#pragma region "Static methods"

	static void registerEmsClass();

#pragma endregion

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 * 
	 * \param[in] idx
	 *    Индекс узела.
	 */
	Node(foundation::Context * context, Node * parent, const NodeIdx & idx);

	/*!
	 * \brief
	 *    Виртуальный еструктор класса.
	 */
	virtual ~Node() = default;

#pragma endregion

	virtual u32_t traverse(utils::Traverser * traverser);

	/*!
	 * \brief
	 *    Добавляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	NodeIdx addChild(Node * child);

	bool insertChild(Node * child, const NodeIdx & idx);

	/*!
	 * \brief
	 *    Удаляет дочерний узел.
	 * 
	 * \param[in] child
	 *    Указатель на дочерний узел.
	 */
	void removeChild(Node * child);

	/*!
	 * \brief
	 *    Возвращает дочерний узел по его идентификатору.
	 * 
	 * \param[in] uid
	 *    Идентификатор узла.
	 * 
	 * \sa
	 *    getChildAt(u32_t targetIdx)
	 */
	Node * getChild(const std::string & uid) const;

	/*!
	 * \brief
	 *    Возвращает дочерний узел по индексу.
	 * 
	 * \param[in] targetIdx
	 *    Индекс дочерний узла.
	 * 
	 * \sa
	 *    getChild(const std::string & uid)
	 */
	Node * getChildAt(u32_t targetIdx) const;

	bool hasChild(const std::string & uid) const;

	/*!
	 * \brief
	 *    Возвращает дочерние узлы.
	 */
	const std::vector<Node *> & getChildren() const;

	/*!
	 * \brief
	 *    Возвращает количество дочерних узлов.
	 */
	u32_t getChildCount();

	/*!
	 * \brief
	 *    Возвращает родительский узел.
	 */
	Node * getParent();

	/*!
	 * \brief
	 *    Устанавливает родительский узел.
	 * 
	 * \param[in] parent
	 *    Указатель на родительский узел.
	 */
	void setParent(Node * parent);

	bool hasParent() const;

	/*!
	 * \brief
	 *    Возвращает индекс узла.
	 */
	NodeIdx getNodeIdx() const;

	/*!
	 * \brief
	 *    Устанавливает индекс узла.
	 * 
	 * \param[in] idx
	 *    Индекс узла.
	 */
	void setNodeIdx(const NodeIdx & idx);

private:
	Node * parent_; /*!< Родительский узел. */
	NodeVec_t children_; /*!< Последовательный контейнер дочерних узлов. */
	NodeIdx nodeIdx_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINER_NODE_HPP
