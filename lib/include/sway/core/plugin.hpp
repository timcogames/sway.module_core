#ifndef SWAY_CORE_PLUGIN_HPP
#define SWAY_CORE_PLUGIN_HPP

#include <sway/core/binding/function.hpp>
#include <sway/core/generic/io/path.hpp>
#include <sway/core/plugininfo.hpp>
#include <sway/namespacemacros.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

struct PluginFunctionSet {};

using DlibHandle_t = void *;
using PluginGetInfoFunc_t = binding::TFunction<PluginInfo()>;
using PluginInitializeFunc_t = binding::TFunction<void(PluginFunctionSet *)>;

class Plugin {
public:
  Plugin(const generic::io::Path &filepath);

  ~Plugin();

  bool isLoaded() const;

  PluginInfo getInfo() const;

  void initialize(PluginFunctionSet *functions);

private:
  DlibHandle_t _handle;
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
