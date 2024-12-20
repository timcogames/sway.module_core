#ifndef SWAY_CORE_DETAIL_NAMED_HPP
#define SWAY_CORE_DETAIL_NAMED_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/detail/symbol.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * @ingroup detail
 * @{
 */

template <typename TYPE, std::size_t N, const s8_t (&SYMBOL)[N]>
struct Named {
  using type_t = TYPE;

  static FORCE_INLINE constexpr auto name = Symbol<N>(SYMBOL);
  static FORCE_INLINE constexpr auto nameCStr = name.getName();
};

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_NAMED_HPP
