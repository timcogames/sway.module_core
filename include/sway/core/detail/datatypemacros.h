#ifndef _SWAY_CORE_DETAIL_DATATYPEMACROS_H
#define _SWAY_CORE_DETAIL_DATATYPEMACROS_H

#define ENUM_DATATYPE(Key, Type) \
	template<> \
	struct EnumToDataType<Key> { \
		using type_t = Type; \
	}; \
	template<> \
	struct DataTypeToEnum<Type> { \
		static constexpr DataType_t value = Key; \
	};

#endif // _SWAY_CORE_DETAIL_DATATYPEMACROS_H
