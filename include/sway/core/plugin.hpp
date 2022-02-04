#ifndef _SWAY_CORE_PLUGIN_H
#define _SWAY_CORE_PLUGIN_H

#include <sway/core/binding/function.h>
#include <sway/core/generic/io/path.h>
#include <sway/core/plugininfo.h>
#include <sway/namespacemacros.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

struct PluginFunctionSet { };

typedef void * DlibHandle_t;
typedef binding::TFunction<PluginInfo ()> PluginGetInfoFunc_t;
typedef binding::TFunction<void (PluginFunctionSet *)> PluginInitializeFunc_t;

class Plugin {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] filepath
	 *    Полный путь к файлу плагина
	 */
	Plugin(const generic::io::Path & filepath);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Plugin();

	bool isLoaded() const;

	/*!
	 * \brief
	 *    Возвращает информацию о плагине.
	 */
	PluginInfo getInfo() const;

	void initialize(PluginFunctionSet * functions);

private:
	DlibHandle_t _handle;
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_PLUGIN_H
