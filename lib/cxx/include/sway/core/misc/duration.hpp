#ifndef SWAY_CORE_MISC_DURATION_HPP
#define SWAY_CORE_MISC_DURATION_HPP

#include <sway/core/misc/chronounits.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

class Duration {
public:
  template <ChronoUnit TUnit>
  static auto of(f64_t val) -> Duration {
    return Duration(val * CHRONO_UNIT_TABLE.at(TUnit));
  }

  Duration()
      : millis_(0) {}

  Duration(f64_t ms)
      : millis_(ms) {}

  ~Duration() = default;

  [[nodiscard]]
  auto asMillis() const -> f64_t {
    return millis_;
  }

  [[nodiscard]]
  auto asSeconds() const -> f64_t {
    return millis_ / CHRONO_UNIT_TABLE.at(ChronoUnit::SECONDS);
  }

  [[nodiscard]]
  auto asMinutes() const -> f64_t {
    return millis_ / CHRONO_UNIT_TABLE.at(ChronoUnit::MINUTES);
  }

  [[nodiscard]]
  auto asHours() const -> f64_t {
    return millis_ / CHRONO_UNIT_TABLE.at(ChronoUnit::HOURS);
  }

private:
  f64_t millis_;
};

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_MISC_DURATION_HPP
