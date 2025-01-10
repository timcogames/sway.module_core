# group `convertors` {#de/df5/group__convertors}

Various helper classes.

## Summary

 Members | Descriptions 
:---|---
`public FORCE_INLINE auto `[`toLower`](#de/df5/group__convertors_1gae29d3586f57303b6b54e4479f02e7af0)`(const std::string & str)` | Converts string to lower case.
`public FORCE_INLINE auto `[`isLower`](#de/df5/group__convertors_1gadddb608d7dee9de9b3417ca7fe514553)`(s8_t raw)` | Checks if the character is a lowercase letter.
`public FORCE_INLINE auto `[`toUpper`](#de/df5/group__convertors_1ga44608aa89f7112ab1764a327ea846c51)`(const std::string & str)` | Converts string to upper case.
`public FORCE_INLINE auto `[`isUpper`](#de/df5/group__convertors_1ga3755a1d79b39a936bdb28217b3171c43)`(s8_t raw)` | Checks if the character is an uppercase letter.
`struct `[`sway::core::ToLowerCase`](#d3/dc2/structsway_1_1core_1_1ToLowerCase) | 
`struct `[`sway::core::ToUpperCase`](#d4/d87/structsway_1_1core_1_1ToUpperCase) | 

## Members

#### `public FORCE_INLINE auto `[`toLower`](#de/df5/group__convertors_1gae29d3586f57303b6b54e4479f02e7af0)`(const std::string & str)` {#de/df5/group__convertors_1gae29d3586f57303b6b54e4479f02e7af0}

Converts string to lower case.

#### Parameters
* `str` String to convert

#### `public FORCE_INLINE auto `[`isLower`](#de/df5/group__convertors_1gadddb608d7dee9de9b3417ca7fe514553)`(s8_t raw)` {#de/df5/group__convertors_1gadddb608d7dee9de9b3417ca7fe514553}

Checks if the character is a lowercase letter.

#### Parameters
* `raw` Character to check. 

#### Returns
true if the character is a lowercase letter, false otherwise.

#### `public FORCE_INLINE auto `[`toUpper`](#de/df5/group__convertors_1ga44608aa89f7112ab1764a327ea846c51)`(const std::string & str)` {#de/df5/group__convertors_1ga44608aa89f7112ab1764a327ea846c51}

Converts string to upper case.

#### Parameters
* `str` String to convert

#### `public FORCE_INLINE auto `[`isUpper`](#de/df5/group__convertors_1ga3755a1d79b39a936bdb28217b3171c43)`(s8_t raw)` {#de/df5/group__convertors_1ga3755a1d79b39a936bdb28217b3171c43}

Checks if the character is an uppercase letter.

#### Parameters
* `raw` Character to check. 

#### Returns
true if the character is an uppercase letter, false otherwise.

## struct `sway::core::ToLowerCase` {#d3/dc2/structsway_1_1core_1_1ToLowerCase}

### Summary

 Members | Descriptions 
:---|---
`public inline u8_t `[`operator()`](#d3/dc2/structsway_1_1core_1_1ToLowerCase_1ac9516dd6d1758466aa13a960421562fa)`(u8_t chr)` | 

### Members

#### `public inline u8_t `[`operator()`](#d3/dc2/structsway_1_1core_1_1ToLowerCase_1ac9516dd6d1758466aa13a960421562fa)`(u8_t chr)` {#d3/dc2/structsway_1_1core_1_1ToLowerCase_1ac9516dd6d1758466aa13a960421562fa}

## struct `sway::core::ToUpperCase` {#d4/d87/structsway_1_1core_1_1ToUpperCase}

### Summary

 Members | Descriptions 
:---|---
`public inline u8_t `[`operator()`](#d4/d87/structsway_1_1core_1_1ToUpperCase_1ad8930aaf10cba0144bd6a261a30b9f51)`(u8_t chr)` | 

### Members

#### `public inline u8_t `[`operator()`](#d4/d87/structsway_1_1core_1_1ToUpperCase_1ad8930aaf10cba0144bd6a261a30b9f51)`(u8_t chr)` {#d4/d87/structsway_1_1core_1_1ToUpperCase_1ad8930aaf10cba0144bd6a261a30b9f51}

