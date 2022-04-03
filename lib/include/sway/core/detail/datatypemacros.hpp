#ifndef SWAY_CORE_DETAIL_DATATYPEMACROS_HPP
#define SWAY_CORE_DETAIL_DATATYPEMACROS_HPP

#define ENUM_DATATYPE(Key, Type)             \
  template <>                                \
  struct EnumToDataType<Key> {               \
    using type_t = Type;                     \
  };                                         \
  template <>                                \
  struct DataTypeToEnum<Type> {              \
    static constexpr DataType_t value = Key; \
  };

#endif
