#ifndef SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP
#define SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP

#include <sway/_stdafx.hpp>
#include <sway/common/representation.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>

namespace sway {

template <>
struct Representation<core::NodeIndexChainTypedefs::Container_t> {
  static auto get(const core::NodeIndexChainTypedefs::Container_t &val) -> std::string {
    std::ostringstream oss;

    oss << "[";
    std::copy(val.begin(), val.end() - 1, std::ostream_iterator<i32_t>(oss, ", "));
    oss << val.back() << "]";

    return oss.str();
  }
};

template <>
struct Representation<core::NodeIndex> {
  static auto get(const core::NodeIndex &value) -> std::string {
    return Representation<core::NodeIndexChainTypedefs::Container_t>::get(value.getChain());
  }
};

}  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEINDEXREPRESENTATION_HPP
