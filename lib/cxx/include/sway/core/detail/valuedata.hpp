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
  PURE_VIRTUAL(auto type() const -> u32_t);
};

template <typename VALUE_TYPE>
struct GenericValueData : public ValueData {
  VALUE_TYPE value;

  GenericValueData(VALUE_TYPE val)
      : value(val) {}

#pragma region "Override ValueData methods"

  MTHD_OVERRIDE(auto type() const -> u32_t) { return detail::toBase(detail::ValueDataTypeToEnum<VALUE_TYPE>::value); }

#pragma endregion
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_VALUEDATA_HPP
