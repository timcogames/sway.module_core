#ifndef SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP
#define SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/misc/string/representation.hpp>

#include <numeric>

namespace sway::core {

template <>
struct Representation<NodeIndexChainTypedefs::Container_t> {
  static auto get(const NodeIndexChainTypedefs::Container_t &val) -> std::string {
    std::ostringstream oss;

    oss << "[";
    std::copy(val.begin(), val.end() - 1, std::ostream_iterator<i32_t>(oss, ", "));
    oss << val.back() << "]";

    return oss.str();
  }
};

template <>
struct Representation<NodeIndex> {
  static auto get(const NodeIndex &value) -> std::string {
    return Representation<NodeIndexChainTypedefs::Container_t>::get(value.getChain());
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP
