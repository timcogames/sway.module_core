#ifndef SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

/**
 * @class Nameable
 * \~english @brief Helper class with a name.
 */
class Nameable {
public:
#pragma region "Ctors/Dtor"

  Nameable(lpcstr_t name)
      : name_(name) {}

  Nameable(const std::string &name)
      : name_(std::move(name)) {}

  Nameable(const Nameable &obj)
      : name_(obj.name_) {}

  ~Nameable() = default;

#pragma endregion

  void setName(lpcstr_t name) { name_ = name; }

  [[nodiscard]] auto getName() const -> std::string const & { return name_; }

  [[nodiscard]] auto hasName() const -> bool { return !name_.empty(); }

protected:
  std::string name_;
};

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_NAMEABLE_HPP
