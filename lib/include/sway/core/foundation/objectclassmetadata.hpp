#ifndef SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
#define SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_PLATFORM_USE_BINDING
#    include <emscripten/bind.h>
#  endif
#endif

#include <cstdlib>  // std::free
#include <cxxabi.h>
#include <memory>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class ObjectClassname {
public:
  static auto demangle(lpcstr_t name) -> std::string {
    int status;
    std::unique_ptr<s8_t, void (*)(void *)> result{abi::__cxa_demangle(name, 0, 0, &status), std::free};

    return (status == 0) ? result.get() : name;
  }

  template <typename T>
  static auto toStr() -> std::string {
    std::string classname = core::foundation::ObjectClassname::demangle(typeid(T).name());
    std::string delimiter = "::";

    return classname.substr(classname.rfind(delimiter) + 2);
  }
};

class ObjectClassMetadata {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  ObjectClassMetadata(lpcstr_t classname, const ObjectClassMetadata *superclass)
      : superclass_(superclass)
      , classname_(classname) {}
  [[nodiscard]] const ObjectClassMetadata *getSuperclass() const { return superclass_; }
  [[nodiscard]] const std::string &getClassname() const { return classname_; }

private:
  const ObjectClassMetadata *superclass_;
  std::string classname_;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#define DECLARE_SUPERCLASS()                                                                       \
  static const sway::core::foundation::ObjectClassMetadata *getObjectClassMetadata() { return 0; } \
  PURE_VIRTUAL(const sway::core::foundation::ObjectClassMetadata *getSuperclass() const);          \
  PURE_VIRTUAL(const std::string &getClassname() const);

#define DECLARE_CLASS_METADATA(objclass, superclass)                                                                 \
  typedef superclass super_t;                                                                                        \
  static const sway::core::foundation::ObjectClassMetadata *getObjectClassMetadata() {                               \
    static const sway::core::foundation::ObjectClassMetadata metadata(#objclass, super_t::getObjectClassMetadata()); \
    return &metadata;                                                                                                \
  }                                                                                                                  \
  MTHD_OVERRIDE(const sway::core::foundation::ObjectClassMetadata *getSuperclass() const) {                          \
    return getObjectClassMetadata()->getSuperclass();                                                                \
  }                                                                                                                  \
  MTHD_OVERRIDE(const std::string &getClassname() const) { return getObjectClassMetadata()->getClassname(); }

#endif  // SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
