#ifndef SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP
#define SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP

namespace sway::core {

/**
 * @ingroup design
 * @{
 */

/**
 * @class Visibleable
 * @brief \~english Helper class for setting and checking the visibility of an object. \~russian Вспомогательный класс
 * для установки и проверки видимости объекта.
 */
class Visibleable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Visibleable()
      : visible_(true) {}

  ~Visibleable() = default;

  /** @} */
#pragma endregion

  void setVisible(bool value) { visible_ = value; }

  [[nodiscard]] auto isVisible() const -> bool { return visible_; }

private:
  bool visible_;
};

/**
 * end of design
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_DESIGN_VISIBLEABLE_HPP
