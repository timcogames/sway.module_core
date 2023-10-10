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
  // clang-format off
  PURE_VIRTUAL(auto serialize() const -> std::string);  // clang-format on

  PURE_VIRTUAL(void deserialize(const std::string &data));
};

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_WEB_BINDINGS)
class EventDataWrapper : public emscripten::wrapper<EventData> {
public:
  EMSCRIPTEN_WRAPPER(EventDataWrapper);

  // clang-format off
  MTHD_OVERRIDE(auto serialize() const -> std::string) {  // clang-format on
    return call<std::string>("serialize");
  }

  MTHD_OVERRIDE(void deserialize(const std::string &data)) { return call<void>("deserialize", data); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTDATA_HPP
