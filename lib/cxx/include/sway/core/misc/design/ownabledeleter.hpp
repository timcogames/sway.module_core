#ifndef SWAY_CORE_MISC_DESIGN_OWNABLEDELETER_HPP
#define SWAY_CORE_MISC_DESIGN_OWNABLEDELETER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/design/_typedefs.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

template <typename TYPE>
struct OwnableDeleter {
  void operator()(OwnableTypedefs::Ptr_t<TYPE> obj) const;
};

/**
 * @}
 */

}  // namespace sway::core

#include <sway/core/misc/design/ownabledeleter.inl>

#endif  // SWAY_CORE_MISC_DESIGN_OWNABLEDELETER_HPP
