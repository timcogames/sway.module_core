#ifndef SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

/**
 * @namespace sway::core::misc
 * {@
 */

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

/**
 * @ingroup design
 * @{
 */

/**
 * @class Enableable
 * \~russian @brief Вспомогательный класс для включения/выключения условного объекта.
 */
class Enableable {
public:
#pragma region "Ctors/Dtor"

  Enableable()
      : enabled_(true) {}

  ~Enableable() = default;

#pragma endregion

  /**
   * \~russian
   * @brief Включает объект и возвращает предыдущее состояние.
   * @return true - если объект ранее был выключен, false - если включен.
   *
   * @example @code{c++}
   *   auto wasEnabled = enableable.enable();
   * @endcode
   */
  auto enable() -> bool {
    auto result = !enabled_;
    enabled_ = true;
    return result;
  }

  /**
   * \~russian @brief Выключает объект и возвращает предыдущее состояние.
   * \~russian @return true - если объект ранее был включен, false - если выключен.
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

  [[nodiscard]] auto isEnabled() const -> bool { return enabled_; }

  /**
   * \~russian @brief Переключает состояние.
   */
  void toggle() { enabled_ = !enabled_; }

private:
  bool enabled_;
};

/**
 * end of design
 * @}
 */

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

/**
 * ends namespace
 * @}
 */

#endif  // SWAY_CORE_MISC_DESIGN_ENABLEABLE_HPP
