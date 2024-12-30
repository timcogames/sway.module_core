#ifndef SWAY_CORE_FOUNDATION_EVENTACTION_HPP
#define SWAY_CORE_FOUNDATION_EVENTACTION_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/emscriptenmacros.hpp>

namespace sway::core {

template <typename TYPE>
class EventAction {
public:
  using EventType_t = TYPE;

#pragma region "Pure virtual methods"

  virtual void apply(std::shared_ptr<TYPE> evt) = 0;

#pragma endregion
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENTACTION_HPP
