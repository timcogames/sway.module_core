#ifndef SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
#define SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP

#include <sway/core/misc/guid.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <optional>
#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template <typename VALUE_TYPE>
class Uniqueable {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Uniqueable(const std::optional<VALUE_TYPE> &uid)
      : uid_(uid) {}

  ~Uniqueable() = default;

#pragma endregion

  [[nodiscard]]
  auto getUid() const -> std::optional<VALUE_TYPE> {
    return uid_;
  }

  void setUid(const std::optional<VALUE_TYPE> &uid) { uid_ = uid; }

private:
  std::optional<VALUE_TYPE> uid_;  // Уникальный идентификатор.
};

#include <sway/core/foundation/uniqueable_embind.inl>

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
