#ifndef SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <utility>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

template <typename TYPE>
class Nameable {
public:
  explicit Nameable(TYPE name)
      : name_(std::move(name)) {}

  auto name() const -> TYPE const & { return name_; }

  void rename(TYPE name) { name_ = std::move(name); }

protected:
  TYPE name_;
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
