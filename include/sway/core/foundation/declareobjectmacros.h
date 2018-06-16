#ifndef SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H
#define SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H

#define DECLARE_OBJECT(TClass, TSuperClass) \
	public: \
	typedef TSuperClass Super; \
	static const sway::core::foundation::ObjectMetadata * getObjectMetadata() { \
		static const sway::core::foundation::ObjectMetadata metadata(#TClass, Super::getObjectMetadata()); \
		return &metadata; \
	} \
	virtual const sway::core::foundation::ObjectMetadata * getSuperclass() const { return getObjectMetadata()->getSuperclass(); } \
	virtual const std::string & getClassName() const { return getObjectMetadata()->getClassName(); }

#endif // SWAY_CORE_FOUNDATION_DECLAREOBJECTMACROS_H
