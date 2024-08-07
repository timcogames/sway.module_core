#ifndef SWAY_CORE_FOUNDATION_EVENTACTION_HPP
#define SWAY_CORE_FOUNDATION_EVENTACTION_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template <typename TYPE>
class EventAction {
public:
  using EventType_t = TYPE;

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void apply(std::shared_ptr<TYPE> evt));

#pragma endregion
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTACTION_HPP
