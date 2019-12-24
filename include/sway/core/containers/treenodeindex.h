#ifndef _SWAY_CORE_CONTAINERS_TREENODEINDEX_H
#define _SWAY_CORE_CONTAINERS_TREENODEINDEX_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <memory>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class TreeNodeIndex {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeNodeIndex(std::vector<s32_t> indexes = std::vector<s32_t>())
		: _indexes(indexes) {
		// Empty
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeNodeIndex(const TreeNodeIndex & parent, s32_t index)
		: _indexes(parent._indexes) {

		_indexes.push_back(index);
	}

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~TreeNodeIndex() = default;

	TreeNodeIndex getParent() const {
		std::vector<s32_t> parentIndexes = _indexes;
		parentIndexes.pop_back();
		return TreeNodeIndex(parentIndexes);
	}

	/*!
	 * \brief
	 *    Возвращает уровень узла в дереве.
	 */
	s32_t getDepth() const {
		return (s32_t) _indexes.size();
	}

	bool isValid() const {
		return getDepth() > 0;
	}

	s32_t operator[](int index) const {
		return _indexes[index];
	}

	std::string toString() const {
		std::string str = "[";

		if (!isValid()) {
			str += "invalid";
		} else {
			for (int i = 0; i < getDepth(); i++) {
				str += std::to_string(_indexes[i]);
				if (i < getDepth() - 1)
					str += ", ";
			}
		}

		str += "]";
		return str;
	}

private:
	std::vector<s32_t> _indexes;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_CONTAINERS_TREENODEINDEX_H
