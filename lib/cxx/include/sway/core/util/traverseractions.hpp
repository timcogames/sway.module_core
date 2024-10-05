#ifndef SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP
#define SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP

#include <sway/enumeratormacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

/**
 * @enum TraverserAction::Enum
 * @brief Перечислитель действий при обходе дерева.
 */

/**
 * @var TraverserAction::Enum::CONTINUE
 * @brief Продолжать обходить.
 */

/**
 * @var TraverserAction::Enum::PRUNE
 * @brief Не навещай дочерние узлы.
 */

/**
 * @var TraverserAction::Enum::ABORT
 * @brief Прервать обход.
 */

DECLARE_ENUM(TraverserAction, CONTINUE, PRUNE, ABORT)

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP
