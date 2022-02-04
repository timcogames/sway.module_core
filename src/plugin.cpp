#include <sway/core/plugin.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/core/runtime/exceptions/librarynotfoundexception.hpp>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.hpp>

#include <dlfcn.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Plugin::Plugin(const generic::io::Path & filepath) {
	if (filepath.isEmpty())
		throw runtime::exceptions::ArgumentNullException("filepath");

	_handle = dlopen(filepath.toString().c_str(), RTLD_LAZY | RTLD_GLOBAL);
	if (!isLoaded())
		throw runtime::exceptions::LibraryNotFoundException(filepath.getFilename(), dlerror());
}

Plugin::~Plugin() {
	dlclose(_handle);
}

bool Plugin::isLoaded() const {
	return _handle != nullptr;
}

PluginInfo Plugin::getInfo() const {
	std::string functionName = std::string("pluginGetInfo");
	PluginGetInfoFunc_t pluginGetInfoFunc;

	pluginGetInfoFunc = (core::binding::ProcAddress_t) dlsym(_handle, functionName.c_str());
	if (pluginGetInfoFunc == nullptr) {
		dlclose(_handle);
		throw runtime::exceptions::SymbolNotFoundException(functionName, dlerror());
	}

	return pluginGetInfoFunc();
}

void Plugin::initialize(PluginFunctionSet * functions) {
	std::string functionName = std::string("pluginInitialize");
	PluginInitializeFunc_t pluginInitializeFunc;

	pluginInitializeFunc = (core::binding::ProcAddress_t) dlsym(_handle, functionName.c_str());
	if (pluginInitializeFunc == nullptr) {
		dlclose(_handle);
		throw runtime::exceptions::SymbolNotFoundException(functionName, dlerror());
	}

	pluginInitializeFunc(functions);
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
