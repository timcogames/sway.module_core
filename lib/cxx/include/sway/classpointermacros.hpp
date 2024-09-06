#ifndef SWAY_CLASSPOINTERMACROS_HPP
#define SWAY_CLASSPOINTERMACROS_HPP

#include <memory>  // weak_ptr, unique_ptr, shared_ptr

#define DECLARE_CLASS_POINTER_TYPES(CLASS)           \
  class CLASS;                                       \
  using CLASS##Ptr_t = CLASS *;                      \
  using CLASS##UniquePtr_t = std::unique_ptr<CLASS>; \
  using CLASS##WeakPtr_t = std::weak_ptr<CLASS>;     \
  using CLASS##SharedPtr_t = std::shared_ptr<CLASS>;

#define DECLARE_CLASS_POINTER_ALIASES(CLASS) \
public:                                      \
  using Ptr_t = CLASS##Ptr_t;                \
  using UniquePtr_t = CLASS##UniquePtr_t;    \
  using WeakPtr_t = CLASS##WeakPtr_t;        \
  using SharedPtr_t = CLASS##SharedPtr_t;

#endif  // SWAY_CLASSPOINTERMACROS_HPP
