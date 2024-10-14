#ifndef SWAY_CONTAINERMACROS_HPP
#define SWAY_CONTAINERMACROS_HPP

#include <sway/numeraltypes.hpp>

#include <array>
#include <vector>

// clang-format off
#define CONTAINER_TYPE_(PRE, TYPE) PRE##TYPE##_t

#define CONTAINER_ITEM_INDEX_TYPE_(PRE) PRE##ItemIndex_t

#define DECLARE_REF_ARRAY(OBJ, SIZE) public: using CONTAINER_TYPE_(Ref, Arr) = std::array<OBJ, SIZE>;

#define DECLARE_PTR_ARRAY(OBJ, TYPE, SIZE) public: using CONTAINER_TYPE_(TYPE, Arr) = std::array<OBJ::TYPE##_t, SIZE>;

#define DECLARE_PTR_VECTOR(OBJ, TYPE) public: using CONTAINER_TYPE_(TYPE, Vec) = std::vector<OBJ::TYPE##_t>;

#define DECLARE_SHARED_PTR_VECTOR(OBJ) DECLARE_PTR_VECTOR(OBJ, SharedPtr)

#define DECLARE_VECTOR(PRE, TYPE)                      \
public:                                                \
  using CONTAINER_ITEM_INDEX_TYPE_(PRE) = i32_t;       \
  using CONTAINER_TYPE_(PRE, Vec) = std::vector<TYPE>;
// clang-format on

#endif  // SWAY_CONTAINERMACROS_HPP
