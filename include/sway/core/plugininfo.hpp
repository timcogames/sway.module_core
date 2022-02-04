#ifndef _SWAY_CORE_PLUGININFO_HPP
#define _SWAY_CORE_PLUGININFO_HPP

#include <sway/core/version.hpp>
#include <sway/namespacemacros.hpp>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

/*!
 * \brief
 *    Общедоступная информация плагина.
 */
struct PluginInfo {
	lpcstr_t name; /*!< Имя плагина. */
	lpcstr_t author; /*!< Автор плагина. */
	lpcstr_t description; /*!< Описание плагина. */
	lpcstr_t url; /*!< URL плагина. */
	lpcstr_t license; /*!< Лицензия плагина. */
	core::Version version; /*!< Версия плагина. */
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_PLUGININFO_HPP
