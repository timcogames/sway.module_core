#ifndef SWAY_CORE_UTIL_OBSERVER_HPP
#define SWAY_CORE_UTIL_OBSERVER_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(util)

using ObserverArray_t = std::vector<class IObserver *>;
using ObserverArrayIterator_t = ObserverArray_t::const_iterator;

/**
 * @class IObserver
 * @brief Интерфейс наблюдателя.
 */
class IObserver {
public:
  using Ptr_t = IObserver *;

#pragma region "Ctors/Dtor"

  virtual ~IObserver() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void update());

#pragma endregion
};

NAMESPACE_END(util)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_UTIL_OBSERVER_HPP
