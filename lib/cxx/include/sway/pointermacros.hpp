#ifndef SWAY_POINTERMACROS_HPP
#define SWAY_POINTERMACROS_HPP

#include <memory>  // weak_ptr, unique_ptr, shared_ptr

// clang-format off
#define DECLARE_PTR(OBJ) class OBJ; using OBJ##Ptr_t = OBJ *;
#define DECLARE_PTR_ALIAS(OBJ) public: using Ptr_t = OBJ##Ptr_t;

#define DECLARE_UNIQUE_PTR(OBJ) class OBJ; using OBJ##UniquePtr_t = std::unique_ptr<OBJ>;
#define DECLARE_UNIQUE_PTR_ALIAS(OBJ) public: using UniquePtr_t = OBJ##UniquePtr_t;

#define DECLARE_WEAK_PTR(OBJ) class OBJ; using OBJ##WeakPtr_t = std::weak_ptr<OBJ>;
#define DECLARE_WEAK_PTR_ALIAS(OBJ) public: using WeakPtr_t = OBJ##WeakPtr_t;

#define DECLARE_SHARED_PTR(OBJ) class OBJ; using OBJ##SharedPtr_t = std::shared_ptr<OBJ>;
#define DECLARE_SHARED_PTR_ALIAS(OBJ) public: using SharedPtr_t = OBJ##SharedPtr_t;

#define DECLARE_JAVASCRIPT_PTR(OBJ) class OBJ; using OBJ##JavaScriptPtr_t = intptr_t;
#define DECLARE_JAVASCRIPT_PTR_ALIAS(OBJ) public: using JavaScriptPtr_t = OBJ##JavaScriptPtr_t;
// clang-format on

#define DECLARE_PTR_TYPES(OBJ) \
  DECLARE_PTR(OBJ)             \
  DECLARE_UNIQUE_PTR(OBJ)      \
  DECLARE_WEAK_PTR(OBJ)        \
  DECLARE_SHARED_PTR(OBJ)      \
  DECLARE_JAVASCRIPT_PTR(OBJ)

#define DECLARE_PTR_ALIASES(OBJ) \
  DECLARE_PTR_ALIAS(OBJ)         \
  DECLARE_UNIQUE_PTR_ALIAS(OBJ)  \
  DECLARE_WEAK_PTR_ALIAS(OBJ)    \
  DECLARE_SHARED_PTR_ALIAS(OBJ)  \
  DECLARE_JAVASCRIPT_PTR_ALIAS(OBJ)

#endif  // SWAY_POINTERMACROS_HPP
