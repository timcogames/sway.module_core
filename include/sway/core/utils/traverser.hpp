#ifndef _SWAY_CORE_UTILS_TRAVERSER_HPP
#define _SWAY_CORE_UTILS_TRAVERSER_HPP

#include <sway/namespacemacros.hpp>
#include <sway/keywords.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

class Visitable;
class Traverser {
public:
	enum class Action : u32_t {
		CONTINUE, /*!< Продолжать обходить. */
		PRUNE, /*!< Не навещай дочерние узлы. */
		ABORT /*!< Прервать обход. */
	};

	PURE_VIRTUAL(u32_t visit(Visitable * node));
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_TRAVERSER_HPP
