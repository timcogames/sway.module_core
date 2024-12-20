#ifndef SWAY_STDAFX_HPP
#define SWAY_STDAFX_HPP

#include <algorithm>  // copy_n
#include <any>
#include <atomic>  // atomic_uint32_t, memory_order_relaxed
#include <cstring>  // memcmp
#include <functional>  // function
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <queue>  // queue
#include <sstream>
#include <string>
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
