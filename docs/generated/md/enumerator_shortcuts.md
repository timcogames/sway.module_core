# group `enumerator_shortcuts` <a id="dc/d0a/group__enumerator__shortcuts"></a>

Convenience aliases for common underlying types.

## Summary

 Members | Descriptions 
:---|---
`define `[`DECLARE_ENUM_U32`](#dc/d0a/group__enumerator__shortcuts_1ga29b9d40fc9f0738213e23d2fb12acddf) | Declares an enum with `[sway::u32_t](./generated/md/undefined.md#d9/d68/namespacesway_1af2929fd1aeba976f2a8d19c3a2ab957e)` underlying type and `INITIAL = GLOB_IDX_INITIAL`.
`define `[`DECLARE_ENUM_IDX`](#dc/d0a/group__enumerator__shortcuts_1gaf7c85b9c3817cd0cc123d5739405e211) | Declares an enum with `[sway::i32_t](./generated/md/undefined.md#d9/d68/namespacesway_1a739251ae3d6b32fe4d79ea4d89c5a061)` underlying type and `INITIAL = GLOB_IDX_INVALID` (typically `-1`).

## Members

#### `define `[`DECLARE_ENUM_U32`](#dc/d0a/group__enumerator__shortcuts_1ga29b9d40fc9f0738213e23d2fb12acddf) <a id="dc/d0a/group__enumerator__shortcuts_1ga29b9d40fc9f0738213e23d2fb12acddf"></a>

Declares an enum with `[sway::u32_t](./generated/md/undefined.md#d9/d68/namespacesway_1af2929fd1aeba976f2a8d19c3a2ab957e)` underlying type and `INITIAL = GLOB_IDX_INITIAL`.

#### Parameters
* `NAME` Enum namespace name. 

* `LIST` X-macro list (see [DECLARE_ENUM](./generated/md/undefined.md#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976)).

```cpp
DECLARE_ENUM_U32(Priority, PRIORITY_LIST)
```

#### `define `[`DECLARE_ENUM_IDX`](#dc/d0a/group__enumerator__shortcuts_1gaf7c85b9c3817cd0cc123d5739405e211) <a id="dc/d0a/group__enumerator__shortcuts_1gaf7c85b9c3817cd0cc123d5739405e211"></a>

Declares an enum with `[sway::i32_t](./generated/md/undefined.md#d9/d68/namespacesway_1a739251ae3d6b32fe4d79ea4d89c5a061)` underlying type and `INITIAL = GLOB_IDX_INVALID` (typically `-1`).

#### Parameters
* `NAME` Enum namespace name. 

* `LIST` X-macro list (see [DECLARE_ENUM](./generated/md/undefined.md#d2/dee/group__enumerator__main_1gaf312bc565b34b59ce00eceefbb0bd976)).

```cpp
DECLARE_ENUM_IDX(IdxType, IDX_LIST)
```

