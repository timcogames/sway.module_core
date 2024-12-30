#ifndef SWAY_CORE_PLUGININFO_HPP
#define SWAY_CORE_PLUGININFO_HPP

#include <sway/core/version.hpp>

#include <string>

namespace sway::core {

/**
 * @brief \~english Plugin information. \~russian Общедоступная информация плагина.
 */
struct PluginInfo {
  lpcstr_t name;  //!< \~english Plugin name. \~russian Имя плагина.
  lpcstr_t author;  //!< \~english Plugin author. \~russian Автор плагина.
  lpcstr_t description;  //!< \~english Plugin description. \~russian Описание плагина.
  lpcstr_t url;  //!< \~english Plugin URL. \~russian URL плагина.
  lpcstr_t license;  //!< \~english Plugin license. \~russian Лицензия плагина.
  core::Version version;  //!< \~english Plugin version. \~russian Версия плагина.
};

}  // namespace sway::core

#endif  // SWAY_CORE_PLUGININFO_HPP
