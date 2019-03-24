#ifndef SWAY_CORE_BINDING_PROCADDRESS_H
#define SWAY_CORE_BINDING_PROCADDRESS_H

#include <sway/namespacemacros.h>
#include <sway/types.h>
#include <boost/function.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(binding)

using ProcAddress_t = void (*)();
using GetProcAddress_t = boost::function<ProcAddress_t (lpcstr_t)>;

NAMESPACE_END(binding)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_BINDING_PROCADDRESS_H
