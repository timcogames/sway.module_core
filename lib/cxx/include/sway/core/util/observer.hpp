#ifndef SWAY_CORE_UTIL_OBSERVER_HPP
#define SWAY_CORE_UTIL_OBSERVER_HPP

#include <sway/core/util/typedefs.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

using ObserverArray_t = std::vector<ObserverPtr_t>;
using ObserverArrayIterator_t = ObserverArray_t::const_iterator;

/**
 * @class Observer
 * @brief Интерфейс наблюдателя.
 */
class Observer {
  DECLARE_CLASS_POINTER_ALIASES(Observer)

public:
#pragma region "Ctors/Dtor"

  DTOR_VIRTUAL_DEFAULT(Observer);

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void update());

#pragma endregion
};

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_UTIL_OBSERVER_HPP
