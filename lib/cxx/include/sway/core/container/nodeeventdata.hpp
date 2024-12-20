#ifndef SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
#define SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP

#include <sway/core/container/nodeindex.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)

struct NodeEventData : public foundation::EventData {
  NodeIndex nodeidx;

#pragma region "Override EventData methods"

  MTHD_VIRTUAL_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  MTHD_VIRTUAL_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
