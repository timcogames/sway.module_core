#ifndef SWAY_DEFINES_HPP
#define SWAY_DEFINES_HPP

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english Generic "don't care" / "invalid" sentinel, equal to `-1`.
 *        \~russian Обобщённый sentinel "don't care" / "invalid", равный `-1`.
 *
 * @see GLOB_IDX_INVALID
 */
#define GLOB_DONT_CARE (-1)

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english Generic "null" / "initial" sentinel, equal to `0`. \~russian
 *        Обобщённый sentinel "null" / "initial", равный `0`.
 *
 * @see GLOB_IDX_INITIAL
 * @see GLOB_UID_INVALID
 */
#define GLOB_NULL 0

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english Invalid index sentinel. Alias for @ref GLOB_DONT_CARE. Used as `INITIAL`
 *        value by @ref DECLARE_ENUM_IDX. \~russian Sentinel недопустимого индекса.
 *        Псевдоним для @ref GLOB_DONT_CARE. Используется как значение `INITIAL` в @ref DECLARE_ENUM_IDX.
 *
 * @see DECLARE_ENUM_IDX
 */
#define GLOB_IDX_INVALID GLOB_DONT_CARE

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english Initial index sentinel. Alias for @ref GLOB_NULL. Used as `INITIAL`
 *        value by @ref DECLARE_ENUM_U32. \~russian Sentinel начального индекса.
 *        Псевдоним для @ref GLOB_NULL. Используется как значение `INITIAL` в @ref DECLARE_ENUM_U32.
 *
 * @see DECLARE_ENUM_U32
 */
#define GLOB_IDX_INITIAL GLOB_NULL

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english Invalid UID sentinel. Alias for @ref GLOB_NULL. \~russian Sentinel
 *        недопустимого UID. Псевдоним для @ref GLOB_NULL.
 *
 * @see GLOB_UID_INITIAL
 */
#define GLOB_UID_INVALID GLOB_NULL

/**
 * @ingroup sway_defines_sentinels
 * @brief \~english First valid UID, equal to `1`. \~russian Первый допустимый UID, равный `1`.
 *
 * @see GLOB_UID_INVALID
 */
#define GLOB_UID_INITIAL 1

/**
 * @ingroup sway_defines_stringify
 *
 * \~english
 * @brief Helper for @ref STRINGIFY: stringifies the argument without expanding it first.
 * @param x Token to stringify.
 * @return String literal.
 * @note Do not use directly; use @ref STRINGIFY instead.
 *
 * \~russian
 * @brief Помощник для @ref STRINGIFY: преобразует аргумент в строку без предварительного раскрытия.
 * @param x Токен для преобразования в строку.
 * @return Строковый литерал.
 * @note Не используйте напрямую; используйте @ref STRINGIFY.
 */
#define STRINGIFY_HELPER(x) #x

/**
 * @ingroup sway_defines_stringify
 *
 * \~english
 * @brief Expands then stringifies the argument.
 * @param x Expression or macro to stringify.
 * @return String literal of the expanded argument.
 *
 * \~russian
 * @brief Раскрывает, затем преобразует аргумент в строку.
 * @param x Выражение или макрос для преобразования в строку.
 * @return Строковый литерал раскрытого аргумента.
 *
 * \~
 * @code
 * #define VERSION 42
 * STRINGIFY_HELPER(VERSION) // -> "VERSION"
 * STRINGIFY(VERSION)        // -> "42"
 * @endcode
 */
#define STRINGIFY(x) STRINGIFY_HELPER(x)

#endif  // SWAY_DEFINES_HPP
