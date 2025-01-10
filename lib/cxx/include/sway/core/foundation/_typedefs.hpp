#ifndef SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
#define SWAY_CORE_FOUNDATION_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

// clang-format off

class Subsystem;
namespace SubsystemTypedefs {
using SharedPtr_t = std::shared_ptr<Subsystem>;
using Container_t = std::unordered_map<std::string, SharedPtr_t>;
template <class TYPE> using OptionalSharedPtr_t = std::optional<std::shared_ptr<TYPE>>;
}  // namespace SubsystemTypedefs

// clang-format on

/**
 * @defgroup foundation The Foundation group
 * @brief \~english Definition of various types. \~russian Определение различных типов.
 */

/**
 * @defgroup context The Context typedefs
 * @ingroup foundation
 * @brief \~english Definition of context types. \~russian Определение типов контекста.
 */

class Context;

/**
 * @defgroup object The Object typedefs
 * @ingroup foundation
 * @brief \~english Definition of object types. \~russian Определение типов объекта.
 */

class Object;

namespace typedefs {
/**
 * @ingroup foundation context
 * @brief \~english Class Context in @link foundation the foundation group@endlink. \~russian Класс Context в @link
 * foundation the foundation group@endlink.
 */
using ContextPtr_t = Context *;

/**
 * @ingroup foundation object
 * @brief \~english Class Object in @link foundation the foundation group@endlink. \~russian Класс Object в @link
 * foundation the foundation group@endlink.
 */
using ObjectPtr_t = Object *;
}  // namespace typedefs

class ObjectClassMetadata;
namespace ObjectClassMetadataTypedefs {
using ConstPtr_t = const ObjectClassMetadata *;
}  // namespace ObjectClassMetadataTypedefs

class EventData;
namespace EventDataTypedefs {
using Ptr_t = EventData *;
}  // namespace EventDataTypedefs

class Eventable;
namespace EventableTypedefs {
using Ptr_t = Eventable *;
}  // namespace EventableTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_TYPEDEFS_HPP
