#ifndef SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

class Visibleable {
public:
#pragma region "Ctors/Dtor"

  Visibleable()
      : visible_(true) {}

  ~Visibleable() = default;

#pragma endregion

  void setVisible(bool value) { visible_ = value; }

  [[nodiscard]] auto isVisible() const -> bool { return visible_; }

private:
  bool visible_;
};

/**
 * end of design
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP
