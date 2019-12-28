#ifndef _SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H
#define _SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H

#define DECLARE_OBJECT(Class, SuperClass) \
	public: \
	typedef SuperClass super_t; \
	static const sway::core::foundation::ObjectMetadata * getObjectMetadata() { \
		static const sway::core::foundation::ObjectMetadata metadata(#Class, super_t::getObjectMetadata()); \
		return &metadata; \
	} \
	virtual const sway::core::foundation::ObjectMetadata * getSuperClass() const { return getObjectMetadata()->getSuperClass(); } \
	virtual const std::string & getClassName() const { return getObjectMetadata()->getClassName(); }

#endif // _SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H
