#ifndef SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
#define SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
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

// clang-format off
#define DECLARE_SUPERCLASS()                                                                                \
public:                                                                                                     \
  static auto getObjectClassMetadata() -> const sway::core::foundation::ObjectClassMetadata * { return 0; } \
  PURE_VIRTUAL(auto getSuperclass() const -> const sway::core::foundation::ObjectClassMetadata *);          \
  PURE_VIRTUAL(auto getClassname() const -> const std::string &);
// clang-format on

// clang-format off
#define DECLARE_CLASS_METADATA(OBJ_CLASS, OBJ_SUPER)                                                             \
public:                                                                                                               \
  typedef OBJ_SUPER super_t;                                                                                     \
  static auto getObjectClassMetadata() -> const sway::core::foundation::ObjectClassMetadata * {                       \
    static const sway::core::foundation::ObjectClassMetadata metadata(#OBJ_CLASS, super_t::getObjectClassMetadata()); \
    return &metadata;                                                                                                 \
  }                                                                                                                   \
  MTHD_OVERRIDE(auto getSuperclass() const -> const sway::core::foundation::ObjectClassMetadata *) {                  \
    return getObjectClassMetadata()->getSuperclass();                                                                 \
  }                                                                                                                   \
  MTHD_OVERRIDE(auto getClassname() const -> const std::string &) {                                                   \
    return getObjectClassMetadata()->getClassname();                                                                  \
  }
// clang-format on

#endif  // SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
