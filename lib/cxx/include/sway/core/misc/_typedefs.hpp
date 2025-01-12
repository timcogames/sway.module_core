#ifndef SWAY_CORE_MISC_TYPEDEFS_HPP
#define SWAY_CORE_MISC_TYPEDEFS_HPP

#include <sway/_stdafx.hpp>
#include <sway/common/numeraltypes.hpp>

namespace sway::core {

namespace DictionaryValueTypedefs {
using Container_t = std::unordered_map<std::string, std::string>;
}  // namespace DictionaryValueTypedefs

class AtomicIdGenBuffer;
namespace AtomicIdGenBufferTypedefs {
using DisposeFunc_t = std::function<void(bool)>;
using FreedContainer_t = std::queue<u32_t>;
using UsageContainer_t = std::unordered_map<u32_t, std::atomic_uint32_t>;
}  // namespace AtomicIdGenBufferTypedefs

// clang-format off

template <typename TYPE> class AtomicIdGenManager;
namespace AtomicIdGenManagerTypedefs {
template <typename TYPE> using UniquePtr_t = std::unique_ptr<TYPE>;
template <typename TYPE> using QueueUniquePtr_t = std::queue<UniquePtr_t<TYPE>>;
using NameToId_t = std::unordered_map<std::string, u32_t>;
template <typename TYPE> using IdToUniquePtr_t = std::unordered_map<u32_t, UniquePtr_t<TYPE>>;
}  // namespace AtomicIdGenManagerTypedefs

// clang-format off

}  // namespace sway::core

#endif  // SWAY_CORE_MISC_TYPEDEFS_HPP
