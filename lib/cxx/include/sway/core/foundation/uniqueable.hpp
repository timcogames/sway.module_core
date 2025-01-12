#ifndef SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
#define SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

template <typename TYPE>
class Uniqueable {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Uniqueable(const std::optional<TYPE> &uid)
      : uniqueId_(uid) {}

  ~Uniqueable() = default;

  /** @} */
#pragma endregion

  [[nodiscard]] auto getUniqueId() const -> std::optional<TYPE> { return uniqueId_; }

  void setUniqueId(const std::optional<TYPE> &uid) { uniqueId_ = uid; }

private:
  std::optional<TYPE> uniqueId_;
};

#include <sway/core/foundation/uniqueable_embind.inl>

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
