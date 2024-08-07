#ifndef SWAY_CORE_FOUNDATION_EVENTDATA_HPP
#define SWAY_CORE_FOUNDATION_EVENTDATA_HPP

#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

struct EventData {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  using Ptr_t = EventData *;

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto serialize() const -> std::string);

  PURE_VIRTUAL(void deserialize(const std::string &data));

#pragma endregion
};

#include <sway/core/foundation/eventdata_embind.inl>

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTDATA_HPP
