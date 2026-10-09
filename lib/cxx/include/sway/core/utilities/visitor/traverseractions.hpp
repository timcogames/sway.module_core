#ifndef SWAY_CORE_UTILITIES_TRAVERSERACTIONS_HPP
#define SWAY_CORE_UTILITIES_TRAVERSERACTIONS_HPP

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

// clang-format off
#define TRAVERSER_ACTION_LIST(ITEM) \
  ITEM(CONTINUE, 1) \
  ITEM(PRUNE, 2) \
  ITEM(ABORT, 3)
// clang-format on

DECLARE_ENUM_U32(TraverserAction, TRAVERSER_ACTION_LIST)

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_TRAVERSERACTIONS_HPP
