#ifndef SWAY_ENUMERATORMACROS_HPP
#define SWAY_ENUMERATORMACROS_HPP

#include <sway/common/numeraltypes.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/defines.hpp>  // GLOB_IDX_INITIAL, GLOB_IDX_INVALID
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

#include <cstddef>
#include <iterator>
#include <string_view>
#include <type_traits>

/**
 * @defgroup enumerator_macros Enumerator macros
 * @ingroup sway_core
 * @brief \~english Macros and helpers for declaring strongly-typed enums with reflection
 *        (string conversion, iteration, range/count queries). \~russian Макросы и хелперы для
 *        объявления строго типизированных enum с рефлексией (преобразование в строку,
 *        итерация, запросы диапазона/количества).
 */

/**
 * @defgroup enumerator_bitmask Bitmask helpers
 * @ingroup enumerator_macros
 * @brief \~english Compile-time bitmask utilities for flag enums. \~russian Утилиты
 *        битовых масок времени компиляции для enum-флагов.
 */

/**
 * @defgroup enumerator_xmacro X-macro helpers
 * @ingroup enumerator_macros
 * @brief \~english Per-item expansion macros consumed by @ref DECLARE_ENUM. \~russian
 *        Макросы поэлементного раскрытия, потребляемые @ref DECLARE_ENUM.
 */

/**
 * @defgroup enumerator_main Main declaration macros
 * @ingroup enumerator_macros
 * @brief \~english Primary macros that declare the enum and its reflection API. \~russian
 *        Основные макросы, объявляющие enum и его API рефлексии.
 */

/**
 * @defgroup enumerator_shortcuts Shortcut macros
 * @ingroup enumerator_macros
 * @brief \~english Convenience aliases for common underlying types. \~russian Удобные
 *        псевдонимы для распространённых базовых типов.
 */

/**
 * @ingroup enumerator_bitmask
 *
 * \~english
 * @brief Compile-time bitmask generator.
 * @tparam N Bit index (0..31).
 * @return Value with only bit @p N set.
 *
 * \~russian
 * @brief Генератор битовой маски времени компиляции.
 * @tparam N Индекс бита (0..31).
 * @return Значение, в котором установлен только бит @p N.
 *
 * \~
 * @code
 * constexpr auto read  = enumBitmask<0>(); // 0b0001
 * constexpr auto write = enumBitmask<1>(); // 0b0010
 * @endcode
 */
template <sway::u32_t N>
[[nodiscard]] constexpr sway::u32_t enumBitmask() noexcept {
  static_assert(N < 32, "enumBitmask: bit index out of range for u32_t");
  return sway::u32_t{1} << N;
}

/**
 * @ingroup enumerator_bitmask
 *
 * \~english
 * @brief Macro wrapper around @ref enumBitmask.
 * @param x Bit index expression.
 * @return Bitmask value.
 *
 * \~russian
 * @brief Макрос-обёртка над @ref enumBitmask.
 * @param x Выражение индекса бита.
 * @return Значение битовой маски.
 *
 * \~
 * @code
 * #define FLAG_LIST(X) \
 *   X(READ,  0)        \
 *   X(WRITE, 1)
 *
 * DECLARE_ENUM(Flags, sway::u32_t, NONE = 0, FLAG_LIST)
 * // Внутри DECLARE_ENUM_FLAG: Flags::Enum::READ = ENUM_BITMASK(0)
 * @endcode
 */
#define ENUM_BITMASK(x) (::enumBitmask<(x)>())

/**
 * @ingroup enumerator_xmacro
 *
 * \~english
 * @brief Expands an item as an enum enumerator with an explicit value.
 * @param NAME  Enumerator name.
 * @param VALUE Enumerator value.
 *
 * \~russian
 * @brief Раскрывает элемент как перечислитель enum с явным значением.
 * @param NAME  Имя перечислителя.
 * @param VALUE Значение перечислителя.
 *
 * \~
 * @code
 * DECLARE_ENUM_ITEM(RED, 1) // -> RED = 1,
 * @endcode
 */
#define DECLARE_ENUM_ITEM(NAME, VALUE) NAME = VALUE,

/**
 * @ingroup enumerator_xmacro
 *
 * \~english
 * @brief Expands an item as a qualified enumerator reference (no value).
 * @param NAME  Enumerator name.
 * @param VALUE Unused.
 *
 * \~russian
 * @brief Раскрывает элемент как квалифицированную ссылку на перечислитель (без значения).
 * @param NAME  Имя перечислителя.
 * @param VALUE Не используется.
 *
 * \~
 * @code
 * DECLARE_ENUM_NAME(RED, 1) // -> Enum::RED,
 * @endcode
 */
#define DECLARE_ENUM_NAME(NAME, VALUE) Enum::NAME,

/**
 * @ingroup enumerator_xmacro
 *
 * \~english
 * @brief Expands an item as a bitmask enumerator.
 * @param NAME  Enumerator name.
 * @param VALUE Bit index (not a value).
 *
 * \~russian
 * @brief Раскрывает элемент как перечислитель-битовую маску.
 * @param NAME  Имя перечислителя.
 * @param VALUE Индекс бита (не значение).
 *
 * \~
 * @code
 * DECLARE_ENUM_FLAG(READ, 0) // -> READ = ENUM_BITMASK(0),
 * @endcode
 */
#define DECLARE_ENUM_FLAG(NAME, VALUE) NAME = ENUM_BITMASK(VALUE),

/**
 * @ingroup enumerator_xmacro
 *
 * \~english
 * @brief Expands an item as a `case` label returning the enumerator name as a
 *        string literal. Used inside @ref DECLARE_ENUM's `toString`.
 * @param NAME  Enumerator name.
 * @param VALUE Unused.
 *
 * \~russian
 * @brief Раскрывает элемент как метку `case`, возвращающую имя перечислителя в виде строкового
 *        литерала. Используется внутри `toString` из @ref DECLARE_ENUM.
 * @param NAME  Имя перечислителя.
 * @param VALUE Не используется.
 *
 * \~
 * @code
 * DECLARE_ENUM_CASE(RED, 1) // -> case Enum::RED: return "RED";
 * @endcode
 */
#define DECLARE_ENUM_CASE(NAME, VALUE) \
  case Enum::NAME:                     \
    return #NAME;

/**
 * @ingroup enumerator_xmacro
 *
 * \~english
 * @brief Expands an item as a `{Enum::NAME, "NAME"}` pair. Useful for building
 *        lookup tables outside the macro.
 * @param NAME  Enumerator name.
 * @param VALUE Unused.
 *
 * \~russian
 * @brief Раскрывает элемент как пару `{Enum::NAME, "NAME"}`.
 *        Полезно для построения таблиц поиска вне макроса.
 * @param NAME  Имя перечислителя.
 * @param VALUE Не используется.
 *
 * \~
 * @code
 * constexpr std::pair<Color::Enum, std::string_view> kTable[] = {
 *   COLOR_LIST(DECLARE_ENUM_STRING_PAIR)
 * };
 * @endcode
 */
#define DECLARE_ENUM_STRING_PAIR(NAME, VALUE) {Enum::NAME, #NAME},

/**
 * @ingroup enumerator_main
 *
 * \~english
 * @brief Declares a strongly-typed `enum class` together with a reflection API:
 *        iteration array, string conversion, range/count queries.
 * @param NAME          Enum namespace name. Generates `NAME::Enum`,
 *                      `NAME::EnumInfo`, `NAME::toString`, `NAME::detail`.
 * @param TYPE          Underlying integral type (e.g. `sway::u32_t`, `sway::i32_t`).
 * @param INITIAL_VALUE Value for the reserved `INITIAL` enumerator.
 * @param LIST          X-macro of the form `#define LIST(X) X(A, 1) X(B, 2)` (no commas between `X(...)`).
 * @warning The identifiers `INITIAL` and `Latest` are reserved inside `NAME::Enum`.
 *
 * \~russian
 * @brief Объявляет строго типизированный `enum class` вместе с API рефлексии: массив итерации,
 *        преобразование в строку, запросы диапазона/количества.
 * @param NAME          Имя пространства имён enum. Генерирует `NAME::Enum`,
 *                      `NAME::EnumInfo`, `NAME::toString`, `NAME::detail`.
 * @param TYPE          Базовый целочисленный тип (например, `sway::u32_t`, `sway::i32_t`).
 * @param INITIAL_VALUE Значение для зарезервированного перечислителя `INITIAL`.
 * @param LIST          X-макрос вида `#define LIST(X) X(A, 1) X(B, 2)` (без запятых между `X(...)`).
 * @warning Идентификаторы `INITIAL` и `Latest` зарезервированы внутри `NAME::Enum`.
 *
 * @par Generated API
 * - `NAME::Enum` — the enum class itself; always contains `INITIAL` and `Latest`.
 * - `NAME::detail::kValues` — `constexpr` array of all enumerators (including `INITIAL`).
 * - `NAME::detail::kCount` — number of enumerators in `kValues`.
 * - `NAME::detail::kInitial` / `NAME::detail::kLatest` — base values of `INITIAL` / `Latest`.
 * - `NAME::toString(Enum)` — `constexpr std::string_view`, `"Unknown"` for unknown values.
 * - `NAME::EnumInfo::getCount()` — total count including `INITIAL`.
 * - `NAME::EnumInfo::getCountWithoutNone()` — `getCount() - 1`.
 * - `NAME::EnumInfo::getRange()` — `Latest - INITIAL` (numeric span).
 * - `NAME::EnumInfo::getRangeWithoutNone()` — `getRange() - 1`.
 *
 * @par Notes
 * - The `LIST` macro must **not** contain commas between `X(...)` entries; @ref
 *   DECLARE_ENUM_ITEM already appends a trailing comma.
 * - `Latest` is an auxiliary enumerator; do not use it as a real value.
 *
 * \~
 * @code
 * // clang-format off
 * #define COLOR_LIST(X) \
 *   X(RED,   1)         \
 *   X(GREEN, 2)         \
 *   X(BLUE,  3)
 * // clang-format on
 *
 * DECLARE_ENUM(Color, sway::u32_t, 0, COLOR_LIST)
 *
 * // Использование:
 * constexpr auto n  = Color::EnumInfo::getCount();             // 4  (INITIAL + 3)
 * constexpr auto r  = Color::EnumInfo::getRange();             // 4  (Latest - INITIAL)
 * constexpr auto s  = Color::toString(Color::Enum::RED);       // "RED"
 *
 * for (auto e : Color::detail::kValues) {
 *   // ...
 * }
 * @endcode
 */
#define DECLARE_ENUM(NAME, TYPE, INITIAL_VALUE, LIST)                                                                \
  namespace NAME {                                                                                                   \
  enum class Enum : TYPE { INITIAL = INITIAL_VALUE, LIST(DECLARE_ENUM_ITEM) Latest };                                \
                                                                                                                     \
  namespace detail {                                                                                                 \
  FORCE_INLINE constexpr Enum kValues[] = {Enum::INITIAL, LIST(DECLARE_ENUM_NAME)};                                  \
  FORCE_INLINE constexpr std::size_t kCount = std::size(kValues);                                                    \
                                                                                                                     \
  FORCE_INLINE constexpr auto kInitial = sway::core::toBase(Enum::INITIAL);                                          \
  FORCE_INLINE constexpr auto kLatest = sway::core::toBase(Enum::Latest);                                            \
  }                                                                                                                  \
                                                                                                                     \
  [[nodiscard]] FORCE_INLINE constexpr std::string_view toString(Enum value) noexcept {                              \
    switch (value) {                                                                                                 \
      LIST(DECLARE_ENUM_CASE)                                                                                        \
      default:                                                                                                       \
        return "Unknown";                                                                                            \
    }                                                                                                                \
  }                                                                                                                  \
                                                                                                                     \
  struct EnumInfo {                                                                                                  \
    [[nodiscard]] static constexpr auto getRange() noexcept -> std::size_t {                                         \
      return static_cast<std::size_t>(detail::kLatest - detail::kInitial);                                           \
    }                                                                                                                \
    [[nodiscard]] static constexpr auto getRangeWithoutNone() noexcept -> std::size_t { return getRange() - 1; }     \
                                                                                                                     \
    [[nodiscard]] static constexpr auto getCount() noexcept -> std::size_t { return detail::kCount; }                \
    [[nodiscard]] static constexpr auto getCountWithoutNone() noexcept -> std::size_t { return detail::kCount - 1; } \
  };                                                                                                                 \
  }

/**
 * @ingroup enumerator_shortcuts
 *
 * \~english
 * @brief Declares an enum with `sway::u32_t` underlying type and `INITIAL = GLOB_IDX_INITIAL`.
 * @param NAME Enum namespace name.
 * @param LIST X-macro list (see @ref DECLARE_ENUM).
 *
 * \~russian
 * @brief Объявляет enum с базовым типом `sway::u32_t` и `INITIAL = GLOB_IDX_INITIAL`.
 * @param NAME Имя пространства имён enum.
 * @param LIST X-макрос-список (см. @ref DECLARE_ENUM).
 *
 * \~
 * @code
 * DECLARE_ENUM_U32(Priority, PRIORITY_LIST)
 * @endcode
 */
#define DECLARE_ENUM_U32(NAME, LIST) DECLARE_ENUM(NAME, sway::u32_t, GLOB_IDX_INITIAL, LIST)

/**
 * @ingroup enumerator_shortcuts
 *
 * \~english
 * @brief Declares an enum with `sway::i32_t` underlying type and `INITIAL = GLOB_IDX_INVALID` (typically `-1`).
 * @param NAME Enum namespace name.
 * @param LIST X-macro list (see @ref DECLARE_ENUM).
 *
 * \~russian
 * @brief Объявляет enum с базовым типом `sway::i32_t` и `INITIAL = GLOB_IDX_INVALID` (обычно `-1`).
 * @param NAME Имя пространства имён enum.
 * @param LIST X-макрос-список (см. @ref DECLARE_ENUM).
 *
 * \~
 * @code
 * DECLARE_ENUM_IDX(IdxType, IDX_LIST)
 * @endcode
 */
#define DECLARE_ENUM_IDX(NAME, LIST) DECLARE_ENUM(NAME, sway::i32_t, GLOB_IDX_INVALID, LIST)

#endif  // SWAY_ENUMERATORMACROS_HPP
