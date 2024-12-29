#ifndef SWAY_STDAFX_HPP
#define SWAY_STDAFX_HPP

#include <algorithm>  // copy_n, remove_if
#include <array>
#include <atomic>  // atomic_uint32_t, memory_order_relaxed
#include <cstdlib>  // rand, malloc, free
#include <cstring>  // memcmp
#include <cxxabi.h>  // __cxa_demangle
#include <functional>  // function
#include <iomanip>  // put_time
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <queue>  // queue
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>  // unordered_map
#include <utility>  // move
#include <vector>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

#endif  // SWAY_STDAFX_HPP
