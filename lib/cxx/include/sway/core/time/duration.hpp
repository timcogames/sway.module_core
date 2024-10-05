#ifndef SWAY_CORE_TIME_DURATION_HPP
#define SWAY_CORE_TIME_DURATION_HPP

#include <sway/core/time/chronounits.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

class Duration {
public:
#pragma region "Static methods"

  template <ChronoUnit UNIT>
  static auto of(f64_t val) -> Duration {
    return Duration(val * CHRONO_UNIT_TABLE.at(UNIT));
  }

#pragma endregion

#pragma region "Ctors/Dtor"

  Duration()
      : ticks_(0) {}

  Duration(f64_t raw)
      : ticks_(raw) {}

  Duration(const Duration &rhs)
      : ticks_(rhs.getRaw()) {}

  ~Duration() = default;

#pragma endregion

  [[nodiscard]]
  auto getRaw() const -> f64_t {
    return ticks_;
  }

  [[nodiscard]]
  auto asMillis() const -> f64_t {
    return ticks_ / CHRONO_UNIT_TABLE.at(ChronoUnit::MILLIS);
  }

  [[nodiscard]]
  auto asSeconds() const -> f64_t {
    return ticks_ / CHRONO_UNIT_TABLE.at(ChronoUnit::SECONDS);
  }

  [[nodiscard]]
  auto asMinutes() const -> f64_t {
    return ticks_ / CHRONO_UNIT_TABLE.at(ChronoUnit::MINUTES);
  }

  [[nodiscard]]
  auto asHours() const -> f64_t {
    return ticks_ / CHRONO_UNIT_TABLE.at(ChronoUnit::HOURS);
  }

private:
  f64_t ticks_;
};

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_TIME_DURATION_HPP
