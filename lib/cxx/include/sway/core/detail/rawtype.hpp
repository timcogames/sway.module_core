#ifndef SWAY_CORE_DETAIL_RAWTYPE_HPP
#define SWAY_CORE_DETAIL_RAWTYPE_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

template <typename DATA_TYPE>
using Unwrap_t = typename std::decay<DATA_TYPE>::type;

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_RAWTYPE_HPP
