#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/optional.hpp>

#include <string>

using namespace sway;
using namespace sway::core::container;

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(sway_core) {
    emscripten::register_vector<int>("IntegerList");
    emscripten::register_vector<double>("DoubleList");
    emscripten::register_vector<std::string>("StringList");

    register_optional<std::shared_ptr<Node>>("std::optional<Node>");
}

EMSCRIPTEN_BINDINGS(sway_core_container) {
    NodeIdx::registerEmClass();
    Node::registerEmClass();
    Hierarchy::registerEmClass();
}
#endif
