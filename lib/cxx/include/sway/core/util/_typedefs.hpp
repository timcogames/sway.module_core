#ifndef SWAY_CORE_UTIL_TYPEDEFS_HPP
#define SWAY_CORE_UTIL_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

class Traverser;
namespace TraverserTypedefs {
using Ptr_t = Traverser *;
}  // namespace TraverserTypedefs

class Visitable;
namespace VisitableTypedefs {
using Ptr_t = Visitable *;
}  // namespace VisitableTypedefs

class Observer;
namespace ObserverTypedefs {
using Ptr_t = Observer *;
using Container_t = std::vector<Ptr_t>;
}  // namespace ObserverTypedefs

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_TYPEDEFS_HPP
