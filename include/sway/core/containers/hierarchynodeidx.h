#ifndef _SWAY_CORE_CONTAINERS_HIERARCHYNODEIDX_H
#define _SWAY_CORE_CONTAINERS_HIERARCHYNODEIDX_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <memory>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class HierarchyNodeIdx {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	HierarchyNodeIdx(std::vector<s32_t> indexes = std::vector<s32_t>());

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	HierarchyNodeIdx(const HierarchyNodeIdx & parent, s32_t idx);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~HierarchyNodeIdx() = default;

#pragma endregion

	HierarchyNodeIdx getParent() const;

	/*!
	 * \brief
	 *    Возвращает уровень узла в дереве.
	 */
	s32_t getDepth() const;

	s32_t getIdxAt(int idx) const;

	bool isValid() const;

private:
	std::vector<s32_t> _indexes;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/containers/hierarchynodeidx.inl>

#endif // _SWAY_CORE_CONTAINERS_HIERARCHYNODEIDX_H
