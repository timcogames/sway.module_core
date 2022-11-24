#ifndef SWAY_CORE_DETAIL_VALUEDATA_HPP
#define SWAY_CORE_DETAIL_VALUEDATA_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

struct ValueData {
  // clang-format off
  PURE_VIRTUAL(auto type() const -> u32_t);  // clang-format on
};

template <typename TValueType>
struct GenericValueData : public ValueData {
  // clang-format off
  MTHD_OVERRIDE(auto type() const -> u32_t) {  // clang-format on
    return detail::toUnderlying(detail::ValueDataTypeToEnum<TValueType>::value);
  }

protected:
  TValueType value;

  GenericValueData(TValueType val)
      : value(val) {}
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
