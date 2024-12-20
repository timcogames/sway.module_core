#ifndef SWAY_CORE_MISC_DESIGN_OWNABLE_HPP
#define SWAY_CORE_MISC_DESIGN_OWNABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/design/_typedefs.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

/**
 * @class Ownable
 * \~english @brief Helper class with an owner.
 */
template <typename TYPE>
class Ownable {
public:
#pragma region "Ctors/Dtor"

  Ownable(OwnerTypedefs::Ptr_t owner)
      : owner_(owner) {}

  Ownable(const Ownable &owner)
      : owner_(owner.owner_) {}

  virtual ~Ownable() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual void release() = 0;

#pragma endregion

  void setOwner(OwnerTypedefs::Ptr_t owner) { owner_ = owner; }

  [[nodiscard]] auto getOwner() const -> OwnerTypedefs::Ptr_t { return owner_; }

protected:
  OwnerTypedefs::Ptr_t owner_;
};

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_OWNABLE_HPP
