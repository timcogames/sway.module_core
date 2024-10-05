#ifndef SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
#define SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/namespacemacros.hpp>

#include <bitset>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(detail)

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

NS_END()  // namespace detail
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
