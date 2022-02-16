#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>

#include <string>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(sway_core) {
    emscripten::register_vector<int>("IntegerList");
    emscripten::register_vector<double>("DoubleList");
    emscripten::register_vector<std::string>("StringList");
}

using namespace sway;
using namespace sway::core::container;

EMSCRIPTEN_BINDINGS(sway_core_container) {
    NodeIdx::registerEmClass();
    Node::registerEmClass();
}
#endif
