#ifndef SWAY_CORE_DETAIL_VALUEDATA_HPP
#define SWAY_CORE_DETAIL_VALUEDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

struct ValueData {
  virtual auto type() const -> u32_t = 0;
};

template <typename VALUE_TYPE>
struct GenericValueData : public ValueData {
  VALUE_TYPE value;

  GenericValueData(VALUE_TYPE val)
      : value(val) {}

#pragma region "Overridden ValueData methods"

  virtual auto type() const -> u32_t override { return toBase(ValueDataTypeToEnum<VALUE_TYPE>::value); }

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_VALUEDATA_HPP
