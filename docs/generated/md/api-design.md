# group `design` {#d9/d1a/group__design}

Various helper classes.

## Summary

 Members | Descriptions 
:---|---
`class `[`sway::core::Owner`](#d8/dba/classsway_1_1core_1_1Owner) | 
`class `[`sway::core::Enableable`](#d0/d00/classsway_1_1core_1_1Enableable) | Helper class for enabling/disabling conditional objects.
`class `[`sway::core::Nameable`](#d9/d81/classsway_1_1core_1_1Nameable) | Helper class with a name.
`class `[`sway::core::Ownable`](#d6/d16/classsway_1_1core_1_1Ownable) | Helper class with an owner.
`class `[`sway::core::Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable) | Helper class for setting and checking the visibility of an object.
`struct `[`sway::core::OwnableDeleter`](#d6/da9/structsway_1_1core_1_1OwnableDeleter) | 

## class `sway::core::Owner` {#d8/dba/classsway_1_1core_1_1Owner}

### Summary

 Members | Descriptions 
:---|---
`public virtual  `[`~Owner`](#d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40)`() = default` | 

### Members

#### `public virtual  `[`~Owner`](#d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40)`() = default` {#d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40}

## class `sway::core::Enableable` {#d0/d00/classsway_1_1core_1_1Enableable}

Helper class for enabling/disabling conditional objects.

### Summary

 Members | Descriptions 
:---|---
`public inline bool `[`enable`](#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)`()` | Enables the object and returns the previous state.
`public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` | Disables the object and returns the previous state.
`public inline bool `[`isEnabled`](#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1)`() const` | Checks if the object is enabled.
`public inline void `[`toggle`](#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258)`()` | Switches the state.

### Members

#### `public inline bool `[`enable`](#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04}

Enables the object and returns the previous state.

#### Returns
true - if the object was previously disabled, false - if enabled.

```cpp
auto wasEnabled = enableable.enable();
```

#### `public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550}

Disables the object and returns the previous state.

#### Returns
true - if the object was previously enabled, false - if disabled.

```cpp
auto wasDisabled = enableable.disable();
```

#### `public inline bool `[`isEnabled`](#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1)`() const` {#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1}

Checks if the object is enabled.

#### Returns
true - if the object is enabled, false - if disabled.

#### `public inline void `[`toggle`](#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258}

Switches the state.

## class `sway::core::Nameable` {#d9/d81/classsway_1_1core_1_1Nameable}

Helper class with a name.

### Summary

 Members | Descriptions 
:---|---
`protected std::string `[`name_`](#d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169) | 

### Members

#### `protected std::string `[`name_`](#d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169) {#d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169}

## class `sway::core::Ownable` {#d6/d16/classsway_1_1core_1_1Ownable}

Helper class with an owner.

### Summary

 Members | Descriptions 
:---|---
`public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` | 
`public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` | 
`public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` | 
`protected `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) | 

### Members

#### `public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` {#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f}

#### `public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` {#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c}

#### `public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` {#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c}

#### `protected `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) {#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4}

## class `sway::core::Visibleable` {#d2/d89/classsway_1_1core_1_1Visibleable}

Helper class for setting and checking the visibility of an object.

### Summary

 Members | Descriptions 
:---|---
`public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` | 
`public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` | 

### Members

#### `public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` {#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1}

#### `public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` {#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99}

## struct `sway::core::OwnableDeleter` {#d6/da9/structsway_1_1core_1_1OwnableDeleter}

### Summary

 Members | Descriptions 
:---|---
`public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` | 

### Members

#### `public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` {#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8}

