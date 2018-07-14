#ifndef SWAY_CORE_DETAIL_TYPEUTILMACROS_H
#define SWAY_CORE_DETAIL_TYPEUTILMACROS_H

#include <sway/core/detail/typeutils.h>

#define DECLARE_TYPE_CONVERTORS(ENUM_VALUE, TYPE) \
	template<> \
	struct TypeToEnum<TYPE> { \
		static constexpr Type_t value = ENUM_VALUE; \
	}; \
	template<> \
	struct EnumToType<ENUM_VALUE> { \
		using rawtype_t = TYPE; \
	};

#endif // SWAY_CORE_DETAIL_TYPEUTILMACROS_H
