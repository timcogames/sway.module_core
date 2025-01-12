#ifndef SWAY_STDAFX_HPP
#define SWAY_STDAFX_HPP

#include <algorithm>  // copy_n, remove_if, transform
#include <array>
#include <atomic>  // atomic_uint32_t, memory_order_relaxed
#include <bitset>
#include <cctype>  // tolower
#include <cstdarg>  // va_start, va_end, va_list
#include <cstddef>
#include <cstdio>  // snprintf
#include <cstdlib>  // rand, malloc, free, atoi, atof
#include <cstring>  // memcmp
#include <cxxabi.h>  // __cxa_demangle
#include <dlfcn.h>  // dlopen, dlclose, dlsym
#include <exception>
#include <functional>  // function
#include <initializer_list>
#include <iomanip>  // put_time
#include <iostream>  // cout
#include <iterator>
#include <map>
#include <memory>  // weak_ptr, unique_ptr, shared_ptr
#include <numeric>
#include <optional>
#include <queue>
#include <sstream>  // stringstream
#include <stdio.h>  // vsnprintf
#include <stdlib.h>  // srand
#include <string>
#include <string_view>
#include <time.h>  // time
#include <type_traits>  // is_same
#include <unordered_map>
#include <utility>  // move, forward
#include <vector>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

#endif  // SWAY_STDAFX_HPP
