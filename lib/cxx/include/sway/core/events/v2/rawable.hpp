#ifndef SWAY_CORE_EVENTS_V2_RAWABLE_HPP
#define SWAY_CORE_EVENTS_V2_RAWABLE_HPP

namespace sway::core::v2 {

template <typename TYPE>
class Rawable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  explicit Rawable(TYPE *raw)
      : raw_(raw) {}

  /** @} */
#pragma endregion

  auto get() const -> TYPE * { return raw_; }

private:
  TYPE *raw_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_RAWABLE_HPP
