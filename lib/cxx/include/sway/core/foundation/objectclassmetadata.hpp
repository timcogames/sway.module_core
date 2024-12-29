#ifndef SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
#define SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/objectclassname.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

class ObjectClassMetadata {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  ObjectClassMetadata(lpcstr_t classname, const ObjectClassMetadata *superclass)
      : superclass_(superclass)
      , classname_(classname) {}

  [[nodiscard]] auto getSuperclass() const -> const ObjectClassMetadata * { return superclass_; }

  [[nodiscard]] auto getClassname() const -> const std::string & { return classname_; }

private:
  const ObjectClassMetadata *superclass_;
  std::string classname_;
};

}  // namespace sway::core

// clang-format off
#define DECLARE_SUPERCLASS()                                                                                \
public:                                                                                                     \
  static auto getObjectClassMetadata() -> const sway::core::ObjectClassMetadata * { return 0; } \
  PURE_VIRTUAL(auto getSuperclass() const -> const sway::core::ObjectClassMetadata *);          \
  PURE_VIRTUAL(auto getClassname() const -> const std::string &);
// clang-format on

// clang-format off
#define DECLARE_CLASS_METADATA(OBJ_CLASS, OBJ_SUPER)                                                             \
public:                                                                                                               \
  typedef OBJ_SUPER super_t;                                                                                     \
  static auto getObjectClassMetadata() -> const sway::core::ObjectClassMetadata * {                       \
    static const sway::core::ObjectClassMetadata metadata(#OBJ_CLASS, super_t::getObjectClassMetadata()); \
    return &metadata;                                                                                                 \
  }                                                                                                                   \
  MTHD_VIRTUAL_OVERRIDE(auto getSuperclass() const -> const sway::core::ObjectClassMetadata *) {                  \
    return getObjectClassMetadata()->getSuperclass();                                                                 \
  }                                                                                                                   \
  MTHD_VIRTUAL_OVERRIDE(auto getClassname() const -> const std::string &) {                                                   \
    return getObjectClassMetadata()->getClassname();                                                                  \
  }
// clang-format on

#endif  // SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
