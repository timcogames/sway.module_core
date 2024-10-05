#ifndef SWAY_CORE_BINDING_PROCADDRESS_HPP
#define SWAY_CORE_BINDING_PROCADDRESS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <functional>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(binding)

using ProcAddress_t = void (*)();
using GetProcAddress_t = std::function<ProcAddress_t(lpcstr_t)>;

NS_END()  // namespace binding
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_BINDING_PROCADDRESS_HPP
