# group `enumerator_bitmask` <a id="df/dfc/group__enumerator__bitmask"></a>

Compile-time bitmask utilities for flag enums.

## Summary

 Members | Descriptions 
:---|---
`define `[`ENUM_BITMASK`](#df/dfc/group__enumerator__bitmask_1ga8a42265b6b47114e2199e022b9aba676) | Macro wrapper around [enumBitmask](./generated/md/undefined.md#df/dfc/group__enumerator__bitmask_1gab6c136d43db22b33a5d0f5f83bc2a4d2).
`public template<>`  <br/>[`sway::u32_t`](./generated/md/undefined.md#d9/d68/namespacesway_1af2929fd1aeba976f2a8d19c3a2ab957e)` `[`enumBitmask`](#df/dfc/group__enumerator__bitmask_1gab6c136d43db22b33a5d0f5f83bc2a4d2)`()` | Compile-time bitmask generator.

## Members

#### `define `[`ENUM_BITMASK`](#df/dfc/group__enumerator__bitmask_1ga8a42265b6b47114e2199e022b9aba676) <a id="df/dfc/group__enumerator__bitmask_1ga8a42265b6b47114e2199e022b9aba676"></a>

Macro wrapper around [enumBitmask](./generated/md/undefined.md#df/dfc/group__enumerator__bitmask_1gab6c136d43db22b33a5d0f5f83bc2a4d2).

#### Parameters
* `x` Bit index expression. 

#### Returns
Bitmask value.

```cpp
#define FLAG_LIST(X) \
  X(READ,  0)        \
  X(WRITE, 1)

DECLARE_ENUM(Flags, sway::u32_t, NONE = 0, FLAG_LIST)
// Внутри DECLARE_ENUM_FLAG: Flags::Enum::READ = ENUM_BITMASK(0)
```

#### `public template<>`  <br/>[`sway::u32_t`](./generated/md/undefined.md#d9/d68/namespacesway_1af2929fd1aeba976f2a8d19c3a2ab957e)` `[`enumBitmask`](#df/dfc/group__enumerator__bitmask_1gab6c136d43db22b33a5d0f5f83bc2a4d2)`()` <a id="df/dfc/group__enumerator__bitmask_1gab6c136d43db22b33a5d0f5f83bc2a4d2"></a>

Compile-time bitmask generator.

#### Parameters
* `N` Bit index (0..31). 

#### Returns
Value with only bit `N` set.

```cpp
constexpr auto read  = enumBitmask<0>(); // 0b0001
constexpr auto write = enumBitmask<1>(); // 0b0010
```

