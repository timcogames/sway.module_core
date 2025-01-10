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
`public inline  `[`Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a10cc407dff878c470d9dde858856c10f)`()` | 
`public  `[`~Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a67b4ca36f2332bfc76adadb1387241b8)`() = default` | 
`public inline bool `[`enable`](#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)`()` | Enables the object and returns the previous state.
`public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` | Disables the object and returns the previous state.
`public inline bool `[`isEnabled`](#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1)`() const` | Checks if the object is enabled.
`public inline void `[`toggle`](#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258)`()` | Switches the state.

### Members

#### `public inline  `[`Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a10cc407dff878c470d9dde858856c10f)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1a10cc407dff878c470d9dde858856c10f}

#### `public  `[`~Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a67b4ca36f2332bfc76adadb1387241b8)`() = default` {#d0/d00/classsway_1_1core_1_1Enableable_1a67b4ca36f2332bfc76adadb1387241b8}

#### `public inline bool `[`enable`](#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04}

Enables the object and returns the previous state.

#### Returns
true - if the object was previously disabled, false - if enabled.

#### `public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` {#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550}

Disables the object and returns the previous state.

#### Returns
true - if the object was previously enabled, false - if disabled.

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
`public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` | 
`public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1)`(const `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable)` & owner)` | 
`public virtual  `[`~Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d)`() = default` | 
`public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` | 
`public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` | 
`public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` | 
`protected `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) | 

### Members

#### `public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` {#d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7}

#### `public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1)`(const `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable)` & owner)` {#d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1}

#### `public virtual  `[`~Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d)`() = default` {#d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d}

#### `public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` {#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f}

#### `public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` {#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c}

#### `public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` {#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c}

#### `protected `[`OwnerTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) {#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4}

## class `sway::core::Visibleable` {#d2/d89/classsway_1_1core_1_1Visibleable}

Helper class for setting and checking the visibility of an object.

### Summary

 Members | Descriptions 
:---|---
`public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` | 
`public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` | 
`public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` | 
`public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` | 

### Members

#### `public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` {#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1}

#### `public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` {#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11}

#### `public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` {#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1}

#### `public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` {#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99}

## struct `sway::core::OwnableDeleter` {#d6/da9/structsway_1_1core_1_1OwnableDeleter}

### Summary

 Members | Descriptions 
:---|---
`public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` | 

### Members

#### `public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/api-undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` {#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8}

