#ifndef SWAY_CORE_RUNTIME_LOG_HPP
#define SWAY_CORE_RUNTIME_LOG_HPP

#include <sway/core/misc/format.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <utility>  // forward

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(runtime)

/**
 * \~english @brief Macro for logging into console.
 * @tparam ARGS
 * @param[in] frmt Format string.
 * @param[in] args Arguments for formatting the string.
 * @return FORCE_NOINLINE
 */
template <class... ARGS>
FORCE_NOINLINE void LOG(const std::string &frmt, ARGS &&...args) {
  std::cout << core::misc::format(frmt.c_str(), std::forward<ARGS>(args)...) << std::endl;
}

NS_END()  // namespace runtime
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_RUNTIME_LOG_HPP
