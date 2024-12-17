#ifndef SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <utility>

namespace sway::core {

template <typename TYPE>
class Nameable {
public:
  explicit Nameable(TYPE name)
      : name_(std::move(name)) {}

  auto getName() const -> TYPE const & { return name_; }

  void rename(TYPE name) { name_ = std::move(name); }

protected:
  TYPE name_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
