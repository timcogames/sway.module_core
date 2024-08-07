#ifndef SWAY_CORE_PLUGIN_HPP
#define SWAY_CORE_PLUGIN_HPP

#include <sway/core/binding/function.hpp>
#include <sway/core/generic/io/path.hpp>
#include <sway/core/plugininfo.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/core/runtime/exceptions/librarynotfoundexception.hpp>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.hpp>
#include <sway/namespacemacros.hpp>

#include <dlfcn.h>  // dlopen, dlclose, dlsym
#include <string>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

struct PluginFunctionSet {
  virtual ~PluginFunctionSet() = default;
};

using DlibHandle_t = void *;
using PluginGetInfoFunc_t = binding::TFunction<PluginInfo()>;
using PluginInitializeFunc_t = binding::TFunction<void(PluginFunctionSet *)>;

class Plugin {
public:
#pragma region "Ctors/Dtor"

  Plugin(const generic::io::Path &filepath, int flags);

  ~Plugin();

#pragma endregion

  [[nodiscard]]
  auto isLoaded() const -> bool;

  [[nodiscard]]
  auto getInfo() const -> PluginInfo;

  void initialize(PluginFunctionSet *functions);

  template <typename CALLBACK>
  auto getMethod(lpcstr_t name) const -> CALLBACK {
    auto func = (core::binding::ProcAddress_t)dlsym(handle_, name);
    if (!func) {
#ifdef EMSCRIPTEN_PLATFORM
      EM_ASM({ console.error(UTF8ToString($0)); }, dlerror());
#else
      throw runtime::exceptions::SymbolNotFoundException(name, dlerror());
#endif
    }

    return static_cast<CALLBACK>(func);
  }

private:
  DlibHandle_t handle_;
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_PLUGIN_HPP
