#ifndef SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP
#define SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP

#include <sway/enumeratormacros.hpp>

namespace sway::core {

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

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_TRAVERSERACTIONS_HPP
