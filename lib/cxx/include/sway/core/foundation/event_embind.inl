#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)

class EventWrapper : public emscripten::wrapper<Event> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  MTHD_OVERRIDE(const ObjectClassMetadata *getSuperclass() const) {
    return call<const ObjectClassMetadata *const>("getSuperclass");
  }

  MTHD_OVERRIDE(const std::string &getClassname() const) { return call<const std::string &>("getClassname"); }

  // clang-format off
  MTHD_OVERRIDE(auto id() const -> std::string) {  // clang-format on
    return call<std::string>("id");
  }

  // clang-format off
  MTHD_OVERRIDE(auto type() const -> u32_t) {  // clang-format on
    return call<u32_t>("type");
  }

  // clang-format off
  MTHD_OVERRIDE(auto data() const -> EventData*) {  // clang-format on
    return call<EventData *const>("data");
  }
};

#endif

inline void Event::bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
  emscripten::class_<Event>("Event")
      .allow_subclass<EventWrapper>("EventWrapper")
      .function("getSuperclass", &Event::getSuperclass, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
      .function("getClassname", &Event::getClassname, emscripten::pure_virtual())
      .function("id", &Event::id, emscripten::pure_virtual())
      .function("type", &Event::type, emscripten::pure_virtual())
      .function("data", &Event::data, emscripten::allow_raw_pointers(), emscripten::pure_virtual());
#endif
}
