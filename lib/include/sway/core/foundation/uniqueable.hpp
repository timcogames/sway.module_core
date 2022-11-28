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

class Uniqueable {
public:
  explicit Uniqueable(const std::optional<std::string> &uid)
      : uid_((uid != std::nullopt) ? uid : misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC)) {}

  ~Uniqueable() = default;

  [[nodiscard]] auto getUid() const { return uid_; }

  void setUid(const std::string &uid) { uid_ = uid; }

private:
  std::optional<std::string> uid_; /*!< Уникальный идентификатор. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_UNIQUEABLE_HPP
