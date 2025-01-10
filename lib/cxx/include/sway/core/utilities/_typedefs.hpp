#ifndef SWAY_CORE_UTILITIES_TYPEDEFS_HPP
#define SWAY_CORE_UTILITIES_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

class Traverser;
class Visitable;
class Observer;

namespace typedefs {

using TraverserPtr_t = Traverser *;

using VisitablePtr_t = Visitable *;

using ObserverPtr_t = Observer *;

using ObserverContainer_t = std::vector<ObserverPtr_t>;

}  // namespace typedefs

}  // namespace sway::core

#endif  // SWAY_CORE_UTILITIES_TYPEDEFS_HPP
