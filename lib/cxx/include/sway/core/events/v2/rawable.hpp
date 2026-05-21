#ifndef SWAY_CORE_EVENTS_V2_RAWABLE_HPP
#define SWAY_CORE_EVENTS_V2_RAWABLE_HPP

namespace sway::core::v2 {

class Rawable {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Rawable(void *raw)
      : raw_(raw) {}

  ~Rawable() = default;

  /** @} */
#pragma endregion

  template <typename TYPE>
  auto getRawAs() -> void * {
    return static_cast<TYPE *>(raw_);
  }

private:
  void *raw_;
};

}  // namespace sway::core::v2

#endif  // SWAY_CORE_EVENTS_V2_RAWABLE_HPP
