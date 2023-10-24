#ifndef SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP

#define DECLARE_VALUEDATA_TYPE_RELATSP(key, valuetype) \
  template <>                                          \
  struct EnumToValueDataType<key> {                    \
    using type_t = valuetype;                          \
  };                                                   \
                                                       \
  template <>                                          \
  struct ValueDataTypeToEnum<valuetype> {              \
    static constexpr ValueDataType value = key;        \
  };

#endif  // SWAY_CORE_DETAIL_VALUEDATATYPEMACROS_HPP
