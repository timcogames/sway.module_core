#ifndef SWAY_CORE_MEMORY_POINTERCAST_HPP
#define SWAY_CORE_MEMORY_POINTERCAST_HPP

#include <sway/namespacemacros.hpp>

#include <memory>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(memory)

/**
 * \~russian @brief Статическое преобразование смарт-указателя.
 * @tparam TO Тип, в который осуществляется преобразование.
 * @tparam FROM Тип, из которого осуществляется преобразование.
 * @param[in] ptr Указатель для преобразования.
 * @return std::unique_ptr<TO> Результат преобразования.
 *
 * \~english @brief Static conversion of a smart pointer.
 * @tparam TO The type to which the conversion is performed.
 * @tparam FROM The type from which to convert.
 * @param[in] ptr The pointer to convert.
 * @return std::unique_ptr<TO> Result of the conversion.
 *
 * @details
 * Usage: Use <tt>staticPointerCast<TO>(std::move(ptr))</tt> to convert a smart pointer to a different type.
 */
template <typename TO, typename FROM>
auto staticPointerCast(std::unique_ptr<FROM> &&ptr) -> std::unique_ptr<TO> {
  return std::unique_ptr<TO>{static_cast<TO *>(ptr.release())};
}

NS_END()  // namespace memory
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MEMORY_POINTERCAST_HPP
