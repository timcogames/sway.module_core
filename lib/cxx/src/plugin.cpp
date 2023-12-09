#include <sway/core/plugin.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Plugin::Plugin(const generic::io::Path &filepath, int flags) {
  if (filepath.isEmpty()) {
    throw runtime::exceptions::ArgumentNullException("filepath");
  }

  handle_ = dlopen(filepath.toString().c_str(), flags);
  if (!isLoaded()) {
#ifdef EMSCRIPTEN_PLATFORM
    EM_ASM({ console.error(UTF8ToString($0)); }, dlerror());
#endif

    throw runtime::exceptions::LibraryNotFoundException(filepath.getFilename(), dlerror());
  }
}

Plugin::~Plugin() { dlclose(handle_); }

auto Plugin::isLoaded() const -> bool { return handle_ != nullptr; }

auto Plugin::getInfo() const -> PluginInfo { return this->getMethod<PluginGetInfoFunc_t>("pluginGetInfo").call(); }

void Plugin::initialize(PluginFunctionSet *functions) {
  this->getMethod<PluginInitializeFunc_t>("pluginInitialize").call(functions);
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
