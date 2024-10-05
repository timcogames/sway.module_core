#ifndef SWAY_CORE_PLUGININFO_HPP
#define SWAY_CORE_PLUGININFO_HPP

#include <sway/core/version.hpp>
#include <sway/namespacemacros.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)

/**
 * @brief Общедоступная информация плагина.
 */
struct PluginInfo {
  lpcstr_t name;  // Имя плагина.
  lpcstr_t author;  // Автор плагина.
  lpcstr_t description;  // Описание плагина.
  lpcstr_t url;  // URL плагина.
  lpcstr_t license;  // Лицензия плагина.
  core::Version version;  // Версия плагина.
};

NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_PLUGININFO_HPP
