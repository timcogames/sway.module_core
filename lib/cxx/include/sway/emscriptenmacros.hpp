#ifndef SWAY_EMSCRIPTENMACROS_HPP
#define SWAY_EMSCRIPTENMACROS_HPP

#define DECLARE_EMSCRIPTEN(ObjectClass)                                                    \
public:                                                                                    \
  using JsPtr_t = intptr_t;                                                                \
                                                                                           \
  static ObjectClass *fromJs(JsPtr_t ptr) { return reinterpret_cast<ObjectClass *>(ptr); } \
  static JsPtr_t toJs(ObjectClass *ptr) { return reinterpret_cast<JsPtr_t>(ptr); }

#define DECLARE_EMSCRIPTEN_BINDING() \
public:                              \
  static void bindEmscriptenClass();

#define EMSCRIPTEN_BINDING_BEGIN(ObjectClass) void ObjectClass::bindEmscriptenClass() {

#define EMSCRIPTEN_BINDING_END() }

#endif  // SWAY_EMSCRIPTENMACROS_HPP
