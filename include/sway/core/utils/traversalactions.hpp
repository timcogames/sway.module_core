#ifndef _SWAY_CORE_UTILS_TRAVERSALACTIONS_HPP
#define _SWAY_CORE_UTILS_TRAVERSALACTIONS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

enum class TraversalAction : u32_t {
	Continue, /*!< Продолжать обходить. */
	Prune, /*!< Не навещай дочерние узлы. */
	Abort /*!< Прервать обход. */
};

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_UTILS_TRAVERSALACTIONS_HPP
