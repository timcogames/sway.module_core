#ifndef SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP
#define SWAY_CORE_FOUNDATION_OBJECTCLASSMETADATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/objectclassname.hpp>
#include <sway/defines.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

class ClassInfo;
using ClassInfoSharedPtr_t = std::shared_ptr<ClassInfo>;
using ClassInfoConstPtr_t = const ClassInfo *;

class ClassInfo {
public:
  ClassInfo(lpcstr_t className, ClassInfoConstPtr_t superInfo)
      : className_(className)
      , superInfo_(superInfo) {}

  [[nodiscard]] auto getClassName() const -> const std::string & { return className_; }

  [[nodiscard]] auto getSuperInfo() const -> ClassInfoConstPtr_t { return superInfo_; }

private:
  std::string className_;
  ClassInfoConstPtr_t superInfo_;
};

template <typename TYPE>
class Super {
public:
  static auto getClassInfo() -> ClassInfoConstPtr_t { return 0; }

#pragma region "Pure virtual methods"

  virtual auto getClassName() const -> const std::string & = 0;

  virtual auto getSuperInfo() const -> ClassInfoConstPtr_t = 0;

#pragma endregion
};

template <template <typename...> class BASE, typename DERIVED>
struct IsBaseOfTemplate {
  template <typename... TS>
  static constexpr std::true_type test(const BASE<TS...> *);
  static constexpr std::false_type test(...);

  using type_t = decltype(test(std::declval<DERIVED *>()));
};

template <template <typename...> class BASE, typename DERIVED>
using IsBaseOfTemplate_t = typename IsBaseOfTemplate<BASE, DERIVED>::type_t;

template <template <typename...> class BASE, typename DERIVED>
inline constexpr bool IsBaseOfTemplate_v = IsBaseOfTemplate_t<BASE, DERIVED>::value;

template <class BASE, class DERIVED>
class Classable : public BASE {
public:
  typedef BASE super_t;

  static auto getClassInfo() -> ClassInfoConstPtr_t {
    static_assert(IsBaseOfTemplate_v<Super, DERIVED>, "DERIVED must inherit from Super");
    static const ClassInfo info(ObjectClassName::toStr<DERIVED>().c_str(), super_t::getClassInfo());
    return &info;
  }

  virtual auto getClassName() const -> const std::string & { return getClassInfo()->getClassName(); }

  virtual auto getSuperInfo() const -> ClassInfoConstPtr_t { return getClassInfo()->getSuperInfo(); }
};

class ObjectClassMetadata {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  ObjectClassMetadata(lpcstr_t classname, ObjectClassMetadataTypedefs::ConstPtr_t superclass)
      : superclass_(superclass)
      , classname_(classname) {}

  [[nodiscard]] auto getSuperclass() const -> ObjectClassMetadataTypedefs::ConstPtr_t { return superclass_; }

  [[nodiscard]] auto getClassname() const -> const std::string & { return classname_; }

private:
  ObjectClassMetadataTypedefs::ConstPtr_t superclass_;
  std::string classname_;
};

}  // namespace sway::core

// clang-format off

#define DECLARE_SUPERCLASS()                                                                                \
public:                                                                                                     \
  static auto getObjectClassMetadata() -> const sway::core::ObjectClassMetadata * { return 0; } \
  PURE_VIRTUAL(auto getSuperclass() const -> const sway::core::ObjectClassMetadata *);          \
  PURE_VIRTUAL(auto getClassname() const -> const std::string &);

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
