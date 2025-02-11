#include <sway/inlinemacros.hpp>

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)

class EventWrapper : public emscripten::wrapper<Event> {
public:
  EMSCRIPTEN_WRAPPER(EventWrapper);

  MTHD_VIRTUAL_OVERRIDE(ObjectClassMetadataTypedefs::ConstPtr_t getSuperclass() const) {
    return call<ObjectClassMetadataTypedefs::ConstPtr_t const>("getSuperclass");
  }

  MTHD_VIRTUAL_OVERRIDE(const std::string &getClassname() const) { return call<const std::string &>("getClassname"); }

  MTHD_VIRTUAL_OVERRIDE(auto getId() const -> std::string) { return call<std::string>("getId"); }

  MTHD_VIRTUAL_OVERRIDE(auto getType() const -> u32_t) { return call<u32_t>("getType"); }

  MTHD_VIRTUAL_OVERRIDE(auto getData() const -> EventDataTypedefs::Ptr_t) { return call<EventDataTypedefs::Ptr_t const>("getData"); }
};

#endif

FORCE_INLINE void Event::bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
  emscripten::class_<Event>("Event")
      .allow_subclass<EventWrapper>("EventWrapper")
      .function("getSuperclass", &Event::getSuperclass, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
      .function("getClassname", &Event::getClassname, emscripten::pure_virtual())
      .function("getId", &Event::getId, emscripten::pure_virtual())
      .function("getType", &Event::getType, emscripten::pure_virtual())
      .function("getData", &Event::getData, emscripten::allow_raw_pointers(), emscripten::pure_virtual());
#endif
}
