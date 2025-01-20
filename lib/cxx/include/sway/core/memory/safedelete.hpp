#ifndef SWAY_CORE_MEMORY_SAFEDELETE_HPP
#define SWAY_CORE_MEMORY_SAFEDELETE_HPP

#include <sway/inlinemacros.hpp>

namespace sway::core {

template <typename TYPE>
FORCE_INLINE void safeDelete(void *ptr) {
  if (ptr != nullptr) {
    delete (TYPE *)ptr;
    ptr = nullptr;
  }
}

template <typename TYPE>
FORCE_INLINE void safeDeleteArray(void *arr) {
  if (arr != nullptr) {
    delete[] (TYPE *)arr;
    arr = nullptr;
  }
}

}  // namespace sway::core

#endif  // SWAY_CORE_MEMORY_SAFEDELETE_HPP
