#ifndef SWAY_CORE_BINDING_PROCADDRESS_HPP
#define SWAY_CORE_BINDING_PROCADDRESS_HPP

#include <sway/_stdafx.hpp>
#include <sway/types.hpp>

namespace sway::core {

using ProcAddress_t = void (*)();
using GetProcAddress_t = std::function<ProcAddress_t(lpcstr_t)>;

}  // namespace sway::core

#endif  // SWAY_CORE_BINDING_PROCADDRESS_HPP
