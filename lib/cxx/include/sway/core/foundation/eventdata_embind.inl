#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
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

inline void EventData::bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
  emscripten::class_<EventData>("EventData")
      .allow_subclass<EventDataWrapper>("EventDataWrapper")
      .function("serialize", &EventData::serialize, emscripten::pure_virtual())
      .function("deserialize", &EventData::deserialize, emscripten::pure_virtual());
#endif
}