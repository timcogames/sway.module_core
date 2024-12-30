#ifndef SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
#define SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/detail/enumutils.hpp>

namespace sway::core {

template <typename ENUM>
class EnumClassBitset {
public:
  EnumClassBitset()
      : flags_() {}

  auto set(ENUM flag) -> EnumClassBitset & {
    flags_.flip(toBase(flag));
    return *this;
  }

  auto rem(ENUM flag) -> EnumClassBitset & {
    flags_.reset(toBase(flag));
    return *this;
  }

  auto has(ENUM flag) const -> bool { return flags_.test(toBase(flag)); }

private:
  std::bitset<toBase(ENUM::Latest)> flags_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
