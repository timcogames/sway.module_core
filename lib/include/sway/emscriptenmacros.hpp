#ifndef SWAY_EMSCRIPTENMACROS_HPP
#define SWAY_EMSCRIPTENMACROS_HPP

#define DECLARE_EMSCRIPTEN_BINDING() static void bindEmscriptenClass();

#define EMSCRIPTEN_BINDING_BEGIN(cls) void cls::bindEmscriptenClass() {

#define EMSCRIPTEN_BINDING_END() }

#endif