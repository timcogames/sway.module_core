#ifndef SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP
#define SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP

#undef SAFE_DELETE_OBJECT
#define SAFE_DELETE_OBJECT(ptr) \
  if ((ptr) != NULL) {          \
    delete (ptr);               \
    (ptr) = NULL;               \
  }

#undef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr) \
  if ((ptr) != NULL) {         \
    delete[] (ptr);            \
    (ptr) = NULL;              \
  }

#endif  // SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP
