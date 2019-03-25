#include <sway/core/plugin.h>
#include <sway/core/runtime/exceptions/argumentnullexception.h>
#include <sway/core/runtime/exceptions/librarynotfoundexception.h>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.h>

#include <boost/format.hpp>
#include <dlfcn.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Plugin::Plugin(boost::filesystem::path filepath) {
	if (filepath.empty())
		throw runtime::exceptions::ArgumentNullException("filepath");

	_handle = dlopen(filepath.c_str(), RTLD_LAZY | RTLD_GLOBAL);
	if (!isLoaded())
		throw runtime::exceptions::LibraryNotFoundException(filepath.stem().string(), dlerror());
}

Plugin::~Plugin() {
	dlclose(_handle);
}

bool Plugin::isLoaded() const {
	return _handle != nullptr;
}

PluginInfo Plugin::getInfo() const {
	std::string pluginGetInfoStr = std::string("pluginGetInfo");
	binding::TFunction<PluginInfo ()> pluginGetInfoFunc;

	pluginGetInfoFunc = (core::binding::ProcAddress_t) dlsym(_handle, pluginGetInfoStr.c_str());
	if (pluginGetInfoFunc == nullptr) {
		dlclose(_handle);
		throw runtime::exceptions::SymbolNotFoundException(pluginGetInfoStr, dlerror());
	}
	
	return pluginGetInfoFunc();
}

void Plugin::initialize(struct PluginFuncSet * functions) {
	std::string pluginInitStr = std::string("pluginInitialize");
	binding::TFunction<void (struct PluginFuncSet *)> pluginInitFunc;

	pluginInitFunc = (core::binding::ProcAddress_t) dlsym(_handle, pluginInitStr.c_str());
	if (pluginInitFunc == nullptr) {
		dlclose(_handle);
		throw runtime::exceptions::SymbolNotFoundException(pluginInitStr, dlerror());
	}

	pluginInitFunc(functions);
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
