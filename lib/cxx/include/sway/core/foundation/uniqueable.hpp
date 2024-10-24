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

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

template <typename VALUE_TYPE>
class Uniqueable {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Uniqueable(const std::optional<VALUE_TYPE> &uid)
      : uniqId_(uid) {}

  ~Uniqueable() = default;

#pragma endregion

  [[nodiscard]] auto getUid() const -> std::optional<VALUE_TYPE> { return uniqId_; }

  void setUid(const std::optional<VALUE_TYPE> &uid) { uniqId_ = uid; }

private:
  std::optional<VALUE_TYPE> uniqId_;
};

#include <sway/core/foundation/uniqueable_embind.inl>

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
