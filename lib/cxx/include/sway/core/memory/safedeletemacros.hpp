#ifndef SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP
#define SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP

// clang-format off
#undef  SAFE_DELETE_OBJECT
#define SAFE_DELETE_OBJECT(OBJ_PTR) \
  if ((OBJ_PTR) != NULL) {          \
    delete (OBJ_PTR);               \
    (OBJ_PTR) = NULL;               \
  }

#undef  SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ARR_PTR) \
  if ((ARR_PTR) != NULL) {         \
    delete[] (ARR_PTR);            \
    (ARR_PTR) = NULL;              \
  }
// clang-format on

#endif  // SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP
