#ifndef SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

/**
 * @class Enableable
 * @brief \~english Helper class for enabling/disabling conditional objects.
 *   \~russian Вспомогательный класс для включения/выключения условного объекта.
 */
class Enableable {
public:
#pragma region "Ctors/Dtor"

  Enableable()
      : enabled_(true) {}

  ~Enableable() = default;

#pragma endregion

  /**
   * \~english @brief Enables the object and returns the previous state.
   * @return true - if the object was previously disabled, false - if enabled.
   *
   * \~russian @brief Включает объект и возвращает предыдущее состояние.
   * @return true - если объект ранее был выключен, false - если включен.
   *
   * @code
   *   auto wasEnabled = enableable.enable();
   * @endcode
   */
  auto enable() -> bool {
    auto result = !enabled_;
    enabled_ = true;
    return result;
  }

  /**
   * \~english @brief Disables the object and returns the previous state.
   * @return true - if the object was previously enabled, false - if disabled.
   *
   * \~russian @brief Выключает объект и возвращает предыдущее состояние.
   * @return true - если объект ранее был включен, false - если выключен.
   *
   * @code
   *   auto wasDisabled = enableable.disable();
   * @endcode
   */
  auto disable() -> bool {
    auto result = enabled_;
    enabled_ = false;
    return result;
  }

  /**
   * \~english @brief Checks if the object is enabled.
   * @return true - if the object is enabled, false - if disabled.
   *
   * \~russian @brief Проверяет, включен ли объект.
   * @return true - если объект включен, false - если выключен.
   */
  [[nodiscard]] auto isEnabled() const -> bool { return enabled_; }

  /**
   * @brief \~english Switches the state. \~russian Переключает состояние.
   */
  void toggle() { enabled_ = !enabled_; }

private:
  bool enabled_;
};

/**
 * end of design
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP
