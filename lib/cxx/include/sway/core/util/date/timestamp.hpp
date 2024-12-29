#ifndef SWAY_CORE_UTIL_DATE_TIMESTAMP_HPP
#define SWAY_CORE_UTIL_DATE_TIMESTAMP_HPP

#include <sway/_stdafx.hpp>
#include <sway/types.hpp>

namespace sway::core {

struct Timestamp {
  /**
   * \~english @brief Converts timestamp to string.
   * @param[in] timestamp Time to convert.
   * @param[in] utc Convert to UTC time.
   *
   * \~russian @brief Конвертирует время в строку.
   * @param[in] timestamp Время для конвертации.
   * @param[in] utc Конвертировать в UTC-время.
   *
   * @return std::string
   */
  static auto toStr(const Timestamp &timestamp, bool utc = true) -> std::string {
    const auto *format = "%Y-%m-%d %H:%M:%S";
    auto now = std::chrono::system_clock::to_time_t(timestamp.value());
    struct std::tm *time = utc ? gmtime(&now) : localtime(&now);
    std::stringstream stream;
    stream << std::put_time(time, format);
    return stream.str();
  }

  Timestamp()
      : duration(0) {}

  auto now() -> std::chrono::time_point<std::chrono::system_clock> {
    auto nowTP = std::chrono::system_clock::now();
    auto nowMs = std::chrono::time_point_cast<std::chrono::milliseconds>(nowTP);
    duration = nowMs.time_since_epoch().count();
    return nowTP;
  }

  [[nodiscard]] auto value() const -> std::chrono::time_point<std::chrono::system_clock> {
    std::chrono::milliseconds durationMs(duration);
    return std::chrono::time_point<std::chrono::system_clock>(durationMs);
  }

  u64_t duration;
};

}  // namespace sway::core

#endif  // SWAY_CORE_UTIL_DATE_TIMESTAMP_HPP
