#ifndef SWAY_CORE_FOUNDATION_EVENTACTION_HPP
#define SWAY_CORE_FOUNDATION_EVENTACTION_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

template <typename TYPE>
class EventAction {
public:
  using EventType_t = TYPE;

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void apply(std::shared_ptr<TYPE> evt));

#pragma endregion
};

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_EVENTACTION_HPP
