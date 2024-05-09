#ifndef SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
#define SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/namespacemacros.hpp>

#include <bitset>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template <typename TEnumClass>
class EnumClassBitset {
public:
  EnumClassBitset()
      : flags_() {}

  auto set(TEnumClass flag) -> EnumClassBitset & {
    flags_.flip(toUnderlying(flag));
    return *this;
  }

  auto rem(TEnumClass flag) -> EnumClassBitset & {
    flags_.reset(toUnderlying(flag));
    return *this;
  }

  auto has(TEnumClass flag) const -> bool { return flags_.test(toUnderlying(flag)); }

private:
  std::bitset<toUnderlying(TEnumClass::Latest)> flags_;
};

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
