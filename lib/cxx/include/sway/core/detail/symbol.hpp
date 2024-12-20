#ifndef SWAY_CORE_DETAIL_SYMBOL_HPP
#define SWAY_CORE_DETAIL_SYMBOL_HPP

#include <sway/_stdafx.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * @ingroup detail
 * @{
 */

template <std::size_t N>
class Symbol {
public:
  constexpr Symbol(const s8_t (&str)[N]) noexcept {
    for (auto i = 0; i < N; i++) {
      name_[i] = str[i];
    }
  }

  template <std::size_t M>
  [[nodiscard]] constexpr auto operator==(const Symbol<M> &other) const noexcept -> bool {
    return (N == M) && (std::memcmp(name_.data(), other.name_.data(), N * sizeof(s8_t)) == 0);
  }

  [[nodiscard]] constexpr auto getName() const noexcept -> lpcstr_t { return name_.data(); }

private:
  std::array<s8_t, N> name_{};
};

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_SYMBOL_HPP
