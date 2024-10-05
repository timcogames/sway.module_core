#ifndef SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP

#define DECLARE_VALUEDATA_TYPE_RELATSP(KEY, VALUE_TYPE) \
  template <>                                           \
  struct EnumToValueDataType<KEY> {                     \
    using type_t = VALUE_TYPE;                          \
  };                                                    \
                                                        \
  template <>                                           \
  struct ValueDataTypeToEnum<VALUE_TYPE> {              \
    static constexpr ValueDataType::Enum value = KEY;   \
  };

#endif  // SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP
