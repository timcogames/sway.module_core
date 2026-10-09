# group `enumerator_main` <a id="d2/dee/group__enumerator__main"></a>

Primary macros that declare the enum and its reflection API.

## Summary

 Members | Descriptions 
:---|---
`define `[`DECLARE_ENUM`](#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976) | Declares a strongly-typed `enum class` together with a reflection API: iteration array, string conversion, range/count queries.

## Members

#### `define `[`DECLARE_ENUM`](#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976) <a id="d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976"></a>

Declares a strongly-typed `enum class` together with a reflection API: iteration array, string conversion, range/count queries.

#### Parameters
* `NAME` Enum namespace name. Generates `NAME::Enum`, `NAME::EnumInfo`, `NAME::toString`, `NAME::detail`. 

* `TYPE` Underlying integral type (e.g. `[sway::u32_t](./generated/md/undefined.md#d9/d68/namespacesway_1af2929fd1aeba976f2a8d19c3a2ab957e)`, `[sway::i32_t](./generated/md/undefined.md#d9/d68/namespacesway_1a739251ae3d6b32fe4d79ea4d89c5a061)`). 

* `INITIAL_VALUE` Value for the reserved `INITIAL` enumerator. 

* `LIST` X-macro of the form `#define LIST(X) X(A, 1) X(B, 2)` (no commas between `X(...)`). 

The identifiers `INITIAL` and `Latest` are reserved inside `NAME::Enum`.

```cpp
// clang-format off
#define COLOR_LIST(X) \
  X(RED,   1)         \
  X(GREEN, 2)         \
  X(BLUE,  3)
// clang-format on

DECLARE_ENUM(Color, sway::u32_t, 0, COLOR_LIST)

// Использование:
constexpr auto n  = Color::EnumInfo::getCount();             // 4  (INITIAL + 3)
constexpr auto r  = Color::EnumInfo::getRange();             // 4  (Latest - INITIAL)
constexpr auto s  = Color::toString(Color::Enum::RED);       // "RED"

for (auto e : Color::detail::kValues) {
  // ...
}
```

