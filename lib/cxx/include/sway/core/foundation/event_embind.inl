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

  MTHD_VIRTUAL_OVERRIDE(const ObjectClassMetadata *getSuperclass() const) { return call<const ObjectClassMetadata *const>("getSuperclass"); }

  MTHD_VIRTUAL_OVERRIDE(const std::string &getClassname() const) { return call<const std::string &>("getClassname"); }

  MTHD_VIRTUAL_OVERRIDE(auto id() const -> std::string) { return call<std::string>("id"); }

  MTHD_VIRTUAL_OVERRIDE(auto type() const -> u32_t) { return call<u32_t>("type"); }

  MTHD_VIRTUAL_OVERRIDE(auto data() const -> EventData::Ptr_t) { return call<EventData::Ptr_t const>("data"); }
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
