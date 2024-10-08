#include <sway/core/plugin.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)

Plugin::Plugin(const generic::io::Path &filepath, int flags) {
  if (filepath.isEmpty()) {
    throw runtime::exceptions::ArgumentNullException("filepath");
  }

  handle_ = dlopen(filepath.toString().c_str(), flags);
  if (!isLoaded()) {
#ifdef EMSCRIPTEN_PLATFORM
    EM_ASM({ console.error(UTF8ToString($0)); }, dlerror());
#else
    throw runtime::exceptions::LibraryNotFoundException(filepath.getFilename(), dlerror());
#endif
  }
}

Plugin::~Plugin() { dlclose(handle_); }

auto Plugin::isLoaded() const -> bool { return handle_ != nullptr; }

auto Plugin::getInfo() const -> PluginInfo { return this->getMethod<PluginGetInfoFunc_t>("pluginGetInfo").call(); }

void Plugin::initialize(PluginFunctionSet *functions) {
  this->getMethod<PluginInitializeFunc_t>("pluginInitialize").call(functions);
}

NS_END()  // namespace core
NS_END()  // namespace sway
