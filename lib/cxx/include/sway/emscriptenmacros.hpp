#ifndef SWAY_EMSCRIPTENMACROS_HPP
#define SWAY_EMSCRIPTENMACROS_HPP

// clang-format off
#define DECLARE_EMSCRIPTEN(OBJ)                                                                                    \
public:                                                                                                            \
  static auto fromJs(OBJ::JavaScriptPtr_t ptr) -> OBJ::Ptr_t { return reinterpret_cast<OBJ::Ptr_t>(ptr); }         \
  static auto toJs(OBJ::Ptr_t ptr) -> OBJ::JavaScriptPtr_t { return reinterpret_cast<OBJ::JavaScriptPtr_t>(ptr); } \
  static auto toJs(OBJ::SharedPtr_t ptr) -> OBJ::JavaScriptPtr_t { return OBJ::toJs(ptr.get()); }
// clang-format on

#define DECLARE_EMSCRIPTEN_BINDING() \
public:                              \
  static void bindEmscriptenClass();

#define EMSCRIPTEN_BINDING_BEGIN(OBJ) void OBJ::bindEmscriptenClass() {

#define EMSCRIPTEN_BINDING_END() }

#endif  // SWAY_EMSCRIPTENMACROS_HPP
