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

template <typename TValueType>
class Uniqueable {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  Uniqueable(const std::optional<TValueType> &uid)
      : uid_(uid) {}

  ~Uniqueable() = default;

  [[nodiscard]] auto getUid() const -> std::optional<TValueType> { return uid_; }

  void setUid(const std::optional<TValueType> &uid) { uid_ = uid; }

private:
  std::optional<TValueType> uid_;  // Уникальный идентификатор.
};

#include <sway/core/foundation/uniqueable_embind.inl>

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
