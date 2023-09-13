#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/uniqueable.hpp>
#include <sway/core/misc/optional.hpp>

#include <string>

using namespace sway;
using namespace sway::core::misc;
using namespace sway::core::foundation;
using namespace sway::core::container;

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)

#  include <emscripten/bind.h>

std::vector<s32_t> toIntegerVec(const emscripten::val &data) {
  return emscripten::convertJSArrayToNumberVector<s32_t>(data);
}

EMSCRIPTEN_BINDINGS(sway_core) {
  emscripten::register_vector<int>("IntegerVec");
  emscripten::function("toIntegerVec", &toIntegerVec);

  emscripten::register_vector<double>("DoubleVec");
  emscripten::register_vector<std::string>("StringVec");
}

EMSCRIPTEN_BINDINGS(sway_core_misc) {
  register_optional<std::string>("StringOpt");
  register_optional<std::shared_ptr<Node>>("NodeOptSmartPtr");

  StringOptional::bindEmscriptenClass();
}

EMSCRIPTEN_BINDINGS(sway_core_container) {
  ObjectClassMetadata::bindEmscriptenClass();
  Event::bindEmscriptenClass();
  EventData::bindEmscriptenClass();
  NodeIdx::bindEmscriptenClass();
  Node::bindEmscriptenClass();
  Hierarchy::bindEmscriptenClass();
}

EMSCRIPTEN_BINDINGS(sway_core_foundation) { Uniqueable<std::string>::bindEmscriptenClass(); }

#endif
