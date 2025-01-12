#ifndef SWAY_CORE_PLUGIN_HPP
#define SWAY_CORE_PLUGIN_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/binding/function.hpp>
#include <sway/core/generic/io/path.hpp>
#include <sway/core/plugininfo.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/core/runtime/exceptions/librarynotfoundexception.hpp>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.hpp>

namespace sway::core {

struct PluginFunctionSet {
  virtual ~PluginFunctionSet() = default;
};

using DlibHandle_t = void *;
using PluginGetInfoFunc_t = TFunction<PluginInfo()>;
using PluginInitializeFunc_t = TFunction<void(PluginFunctionSet *)>;

class Plugin {
public:
#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Plugin(const Path &filepath, int flags);

  ~Plugin();

  /** @} */
#pragma endregion

  [[nodiscard]] auto isLoaded() const -> bool;

  [[nodiscard]] auto getInfo() const -> PluginInfo;

  void initialize(PluginFunctionSet *functions);

  template <typename CALLBACK>
  auto getMethod(lpcstr_t name) const -> CALLBACK {
    auto func = (ProcAddress_t)dlsym(handle_, name);
    if (!func) {
#ifdef EMSCRIPTEN_PLATFORM
      EM_ASM({ console.error(UTF8ToString($0)); }, dlerror());
#else
      throw SymbolNotFoundException(name, dlerror());
#endif
    }

    return static_cast<CALLBACK>(func);
  }

private:
  DlibHandle_t handle_;
};

}  // namespace sway::core

#endif  // SWAY_CORE_PLUGIN_HPP
