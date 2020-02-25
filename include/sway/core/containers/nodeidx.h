#ifndef _SWAY_CORE_CONTAINERS_NODEIDX_H
#define _SWAY_CORE_CONTAINERS_NODEIDX_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <memory>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

class NodeIdx {
public:
#pragma region "Static methods"

	static void registerEmsClass();

#pragma endregion

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	NodeIdx(std::vector<s32_t> indexes = std::vector<s32_t>());

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	NodeIdx(const NodeIdx & parent, s32_t idx);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~NodeIdx() = default;

#pragma endregion

	NodeIdx getParent() const;

	/*!
	 * \brief
	 *    Возвращает уровень узла в дереве.
	 */
	s32_t getDepth() const;

	s32_t getIdxAt(int idx) const;

	bool isValid() const;

private:
	std::vector<s32_t> indexes_;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/containers/nodeidx.inl>

#endif // _SWAY_CORE_CONTAINERS_NODEIDX_H
