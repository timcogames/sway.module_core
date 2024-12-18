#ifndef SWAY_CORE_MISC_FORMAT_HPP
#define SWAY_CORE_MISC_FORMAT_HPP

#include <sway/inlinemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <cstdarg>  // va_start, va_end, std::va_list
#include <stdio.h>  // vsnprintf
#include <string>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

FORCE_INLINE auto format(lpcstr_t const fmt, ...) -> std::string {
  auto temp = std::vector<s8_t>();
  auto size = std::size_t(100);
  std::va_list args;
  while (temp.size() <= size) {
    temp.resize(size + 1);
    va_start(args, fmt);
    int nsize = vsnprintf(temp.data(), temp.size(), fmt, args);
    va_end(args);

    if (nsize < 0) {
      return std::string();
    }

    size = static_cast<std::size_t>(nsize);
  }

  return std::string(temp.data(), size);
}

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_FORMAT_HPP
