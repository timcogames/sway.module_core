#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>

using namespace sway::core::container;

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(sway_core_container) {
    NodeIdx::registerEmClass();
    Node::registerEmClass();
}
#endif