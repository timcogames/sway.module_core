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
      : values_() {}

  auto test(TEnumClass val) const -> bool { return values_.test(toUnderlying(val)); }

  auto reset(TEnumClass val) -> EnumClassBitset & {
    values_.reset(toUnderlying(val));
    return *this;
  }

  auto flip(TEnumClass val) -> EnumClassBitset & {
    values_.flip(toUnderlying(val));
    return *this;
  }

private:
  std::bitset<toUnderlying(TEnumClass::Latest)> values_;
};

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_ENUMCLASSBITSET_HPP
