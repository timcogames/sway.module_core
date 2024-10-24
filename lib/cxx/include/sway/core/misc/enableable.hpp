#ifndef SWAY_CORE_MISC_ENABLEABLE_HPP
#define SWAY_CORE_MISC_ENABLEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

class Enableable {
public:
#pragma region "Ctors/Dtor"

  Enableable()
      : enabled_(true) {}

  DTOR_DEFAULT(Enableable);

#pragma endregion

  void enable() { enabled_ = true; }

  void disable() { enabled_ = false; }

  [[nodiscard]] auto isEnabled() const -> bool { return enabled_; }

  void toggle() { enabled_ = !enabled_; }

private:
  bool enabled_;
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_ENABLEABLE_HPP
