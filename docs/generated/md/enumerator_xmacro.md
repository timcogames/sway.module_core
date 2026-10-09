# group `enumerator_xmacro` <a id="dd/dfe/group__enumerator__xmacro"></a>

Per-item expansion macros consumed by [DECLARE_ENUM](./generated/md/undefined.md#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976).

## Summary

 Members | Descriptions 
:---|---
`define `[`DECLARE_ENUM_ITEM`](#dd/dfe/group__enumerator__xmacro_1ga0d8c68ff2c4e7d1b45c246e85070c0ac) | Expands an item as an enum enumerator with an explicit value.
`define `[`DECLARE_ENUM_NAME`](#dd/dfe/group__enumerator__xmacro_1gafc74422ab94fc9b36cbf5ed2ec8cc4fb) | Expands an item as a qualified enumerator reference (no value).
`define `[`DECLARE_ENUM_FLAG`](#dd/dfe/group__enumerator__xmacro_1gae411d3d587936e98d4f7acb5ceba52d5) | Expands an item as a bitmask enumerator.
`define `[`DECLARE_ENUM_CASE`](#dd/dfe/group__enumerator__xmacro_1ga3f182501146ad0795222ac1b088cf930) | Expands an item as a `case` label returning the enumerator name as a string literal. Used inside [DECLARE_ENUM](./generated/md/undefined.md#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976)'s `toString`.
`define `[`DECLARE_ENUM_STRING_PAIR`](#dd/dfe/group__enumerator__xmacro_1ga765d7c6c47f975dd66eebb4f456e130a) | Expands an item as a `{Enum::NAME, "NAME"}` pair. Useful for building lookup tables outside the macro.

## Members

#### `define `[`DECLARE_ENUM_ITEM`](#dd/dfe/group__enumerator__xmacro_1ga0d8c68ff2c4e7d1b45c246e85070c0ac) <a id="dd/dfe/group__enumerator__xmacro_1ga0d8c68ff2c4e7d1b45c246e85070c0ac"></a>

Expands an item as an enum enumerator with an explicit value.

#### Parameters
* `NAME` Enumerator name. 

* `VALUE` Enumerator value.

```cpp
DECLARE_ENUM_ITEM(RED, 1) // -> RED = 1,
```

#### `define `[`DECLARE_ENUM_NAME`](#dd/dfe/group__enumerator__xmacro_1gafc74422ab94fc9b36cbf5ed2ec8cc4fb) <a id="dd/dfe/group__enumerator__xmacro_1gafc74422ab94fc9b36cbf5ed2ec8cc4fb"></a>

Expands an item as a qualified enumerator reference (no value).

#### Parameters
* `NAME` Enumerator name. 

* `VALUE` Unused.

```cpp
DECLARE_ENUM_NAME(RED, 1) // -> Enum::RED,
```

#### `define `[`DECLARE_ENUM_FLAG`](#dd/dfe/group__enumerator__xmacro_1gae411d3d587936e98d4f7acb5ceba52d5) <a id="dd/dfe/group__enumerator__xmacro_1gae411d3d587936e98d4f7acb5ceba52d5"></a>

Expands an item as a bitmask enumerator.

#### Parameters
* `NAME` Enumerator name. 

* `VALUE` Bit index (not a value).

```cpp
DECLARE_ENUM_FLAG(READ, 0) // -> READ = ENUM_BITMASK(0),
```

#### `define `[`DECLARE_ENUM_CASE`](#dd/dfe/group__enumerator__xmacro_1ga3f182501146ad0795222ac1b088cf930) <a id="dd/dfe/group__enumerator__xmacro_1ga3f182501146ad0795222ac1b088cf930"></a>

Expands an item as a `case` label returning the enumerator name as a string literal. Used inside [DECLARE_ENUM](./generated/md/undefined.md#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976)'s `toString`.

#### Parameters
* `NAME` Enumerator name. 

* `VALUE` Unused.

```cpp
DECLARE_ENUM_CASE(RED, 1) // -> case Enum::RED: return "RED";
```

#### `define `[`DECLARE_ENUM_STRING_PAIR`](#dd/dfe/group__enumerator__xmacro_1ga765d7c6c47f975dd66eebb4f456e130a) <a id="dd/dfe/group__enumerator__xmacro_1ga765d7c6c47f975dd66eebb4f456e130a"></a>

Expands an item as a `{Enum::NAME, "NAME"}` pair. Useful for building lookup tables outside the macro.

#### Parameters
* `NAME` Enumerator name. 

* `VALUE` Unused.

```cpp
constexpr std::pair<Color::Enum, std::string_view> kTable[] = {
  COLOR_LIST(DECLARE_ENUM_STRING_PAIR)
};
```

