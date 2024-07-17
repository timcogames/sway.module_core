#ifndef SWAY_EMSCRIPTENMACROS_HPP
#define SWAY_EMSCRIPTENMACROS_HPP

#define DECLARE_EMSCRIPTEN(OBJ_CLASS)                                                  \
public:                                                                                \
  using JsPtr_t = intptr_t;                                                            \
                                                                                       \
  static OBJ_CLASS *fromJs(JsPtr_t ptr) { return reinterpret_cast<OBJ_CLASS *>(ptr); } \
  static JsPtr_t toJs(OBJ_CLASS *ptr) { return reinterpret_cast<JsPtr_t>(ptr); }

#define DECLARE_EMSCRIPTEN_BINDING() \
public:                              \
  static void bindEmscriptenClass();

#define EMSCRIPTEN_BINDING_BEGIN(OBJ_CLASS) void OBJ_CLASS::bindEmscriptenClass() {

#define EMSCRIPTEN_BINDING_END() }

#endif  // SWAY_EMSCRIPTENMACROS_HPP
