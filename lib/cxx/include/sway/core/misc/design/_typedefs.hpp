#ifndef SWAY_CORE_MISC_DESIGN_TYPEDEFS_HPP
#define SWAY_CORE_MISC_DESIGN_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

class Owner;
namespace OwnerTypedefs {
using Ptr_t = Owner *;
using WeakPtr_t = std::weak_ptr<Owner>;
}  // namespace OwnerTypedefs

// clang-format off

template <typename TYPE> class Ownable;
namespace OwnableTypedefs {
template <typename TYPE> using Ptr_t = Ownable<TYPE> *;
template <typename TYPE, typename DELETER> using UniquePtr_t = std::unique_ptr<Ownable<TYPE>, DELETER>;
}  // namespace OwnableTypedefs

// clang-format on

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_TYPEDEFS_HPP
