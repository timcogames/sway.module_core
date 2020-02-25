#ifndef _SWAY_CORE_FOUNDATION_CONTEXT_H
#define _SWAY_CORE_FOUNDATION_CONTEXT_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context {
public:
	static void registerEmsClass();

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Context();

	/*!
	 * \brief
	 *    Деструктор класса.
	 *    Освобождает захваченные ресурсы.
	 */
	~Context() = default;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_FOUNDATION_CONTEXT_H
