#ifndef SWAY_CORE_STD_STRING_EXTENSIONS_CASES_HPP
#define SWAY_CORE_STD_STRING_EXTENSIONS_CASES_HPP

#include <sway/_stdafx.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * @defgroup convertors String Convertors
 * @brief \~english Various helper classes. \~russian Различные вспомогательные классы.
 */

/**
 * @addtogroup convertors
 * @{
 */

struct ToLowerCase {
  auto operator()(u8_t chr) -> u8_t { return std::tolower(chr); }
};

/**
 * \~english
 * @brief Converts string to lower case
 * @param[in] str String to convert
 *
 * \~russian
 * @brief Преобразует строку в нижний регистр
 * @param[in] str Строка для конвертации
 *
 * @return std::string
 */
FORCE_INLINE auto toLower(const std::string &str) -> std::string {
  std::string result = str;
  std::transform(result.cbegin(), result.cend(), result.begin(), ToLowerCase());
  return result;
}

/**
 * \~english
 * @brief Checks if the character is a lowercase letter.
 * @param[in] raw Character to check.
 * @return true if the character is a lowercase letter, false otherwise.
 *
 * \~russian
 * @brief Проверяет, является ли символ строчной буквой.
 * @param[in] raw Символ для проверки.
 * @return true - если символ является строчной буквой, false - в противном случае.
 */
FORCE_INLINE auto isLower(s8_t raw) -> bool { return 'a' <= raw && raw <= 'z'; }

struct ToUpperCase {
  auto operator()(u8_t chr) -> u8_t { return std::toupper(chr); }
};

/**
 * \~english
 * @brief Converts string to upper case
 * @param[in] str String to convert
 *
 * \~russian
 * @brief Преобразует строку в верхний регистр
 * @param[in] str Строка для конвертации
 *
 * @return std::string
 */
FORCE_INLINE auto toUpper(const std::string &str) -> std::string {
  std::string result = str;
  std::transform(result.cbegin(), result.cend(), result.begin(), ToUpperCase());
  return result;
}

/**
 * \~english
 * @brief Checks if the character is an uppercase letter.
 * @param[in] raw Character to check.
 * @return true if the character is an uppercase letter, false otherwise.
 *
 * \~russian
 * @brief Проверяет, является ли символ заглавной буквой.
 * @param[in] raw Символ для проверки.
 * @return true - если символ является заглавной буквой, false - в противном случае.
 */
FORCE_INLINE auto isUpper(s8_t raw) -> bool { return 'A' <= raw && raw <= 'Z'; }

/**
 * @}
 */

}  // namespace sway::core

#endif  // SWAY_CORE_STD_STRING_EXTENSIONS_CASES_HPP
