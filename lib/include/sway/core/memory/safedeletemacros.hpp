#ifndef SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP
#define SWAY_CORE_MEMORY_SAFEDELETEMACROS_HPP

#undef SAFE_DELETE

#define SAFE_DELETE(object) \
  if ((object) != NULL) {   \
    delete (object);        \
    (object) = NULL;        \
  }

#undef SAFE_DELETE_ARRAY

#define SAFE_DELETE_ARRAY(array) \
  if ((array) != NULL) {         \
    delete[](array);             \
    (array) = NULL;              \
  }

#endif
