#ifndef SWAY_EMSCRIPTENMACROS_HPP
#define SWAY_EMSCRIPTENMACROS_HPP

#define DECLARE_EMSCRIPTEN_BINDING() \
public:                              \
  static void bindEmscriptenClass();

#define EMSCRIPTEN_BINDING_BEGIN(objclass) void objclass::bindEmscriptenClass() {

#define EMSCRIPTEN_BINDING_END() }

#endif  // SWAY_EMSCRIPTENMACROS_HPP
