#ifndef SWAY_CORE_BINDING_PROCADDRESS_HPP
#define SWAY_CORE_BINDING_PROCADDRESS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <functional>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(binding)

using ProcAddress_t = void (*)();
using GetProcAddress_t = std::function<ProcAddress_t(lpcstr_t)>;

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_BINDING_PROCADDRESS_HPP
