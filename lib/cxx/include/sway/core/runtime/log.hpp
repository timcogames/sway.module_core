#ifndef SWAY_CORE_RUNTIME_LOG_HPP
#define SWAY_CORE_RUNTIME_LOG_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * \~english @brief Macro for logging into console.
 * @tparam ARGS
 * @param[in] frmt Format string.
 * @param[in] args Arguments for formatting the string.
 * @return FORCE_NOINLINE
 */
template <class... ARGS>
FORCE_NOINLINE void LOG(const std::string &frmt, ARGS &&...args) {
  std::cout << misc::format(frmt.c_str(), std::forward<ARGS>(args)...) << std::endl;
}

}  // namespace sway::core

#endif  // SWAY_CORE_RUNTIME_LOG_HPP
