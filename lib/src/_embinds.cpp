#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/optional.hpp>

#include <string>

using namespace sway;
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

  register_optional<std::shared_ptr<Node>>("NodeOptSmartPtr");
}

EMSCRIPTEN_BINDINGS(sway_core_container) {
  ObjectClassMetadata::bindEmscriptenClass();
  Event::registerEmsClass();
  NodeIdx::bindEmscriptenClass();
  Node::bindEmscriptenClass();
  Hierarchy::bindEmscriptenClass();
}

#endif
