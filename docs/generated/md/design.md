# group `design` <a id="d9/d1a/group__design"></a>

Various helper classes.

## Summary

 Members | Descriptions 
:---|---
`class `[`sway::core::Symbol`](#d4/dbe/classsway_1_1core_1_1Symbol) | 
`class `[`sway::core::Owner`](#d8/dba/classsway_1_1core_1_1Owner) | 
`class `[`sway::core::Enableable`](#d0/d00/classsway_1_1core_1_1Enableable) | Helper class for enabling/disabling conditional objects.
`class `[`sway::core::Nameable`](#d9/d81/classsway_1_1core_1_1Nameable) | Helper class with a name.
`class `[`sway::core::Ownable`](#d6/d16/classsway_1_1core_1_1Ownable) | Helper class with an owner.
`class `[`sway::core::Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable) | Helper class for setting and checking the visibility of an object.
`struct `[`sway::core::Named`](#d0/d2a/structsway_1_1core_1_1Named) | 
`struct `[`sway::core::OwnableDeleter`](#d6/da9/structsway_1_1core_1_1OwnableDeleter) | 

## class `sway::core::Symbol` <a id="d4/dbe/classsway_1_1core_1_1Symbol"></a>

### Summary

 Members | Descriptions 
:---|---
`public inline constexpr `[`Symbol`](#d4/dbe/classsway_1_1core_1_1Symbol_1a1e70e8964fb1a2e57bdd670b380b0e93)`(const s8_t(&) str) noexcept` | 
`public template<>`  <br/>`inline bool `[`operator==`](#d4/dbe/classsway_1_1core_1_1Symbol_1a57103a1c65e17c588cd9b51c02bb570e)`(const `[`Symbol`](#d4/dbe/classsway_1_1core_1_1Symbol)`< M > & other) const noexcept` | 
`public inline lpcstr_t `[`getName`](#d4/dbe/classsway_1_1core_1_1Symbol_1a1a5956fdcf863d075adeee18fa758de3)`() const noexcept` | 

### Members

#### `public inline constexpr `[`Symbol`](#d4/dbe/classsway_1_1core_1_1Symbol_1a1e70e8964fb1a2e57bdd670b380b0e93)`(const s8_t(&) str) noexcept` <a id="d4/dbe/classsway_1_1core_1_1Symbol_1a1e70e8964fb1a2e57bdd670b380b0e93"></a>

#### `public template<>`  <br/>`inline bool `[`operator==`](#d4/dbe/classsway_1_1core_1_1Symbol_1a57103a1c65e17c588cd9b51c02bb570e)`(const `[`Symbol`](#d4/dbe/classsway_1_1core_1_1Symbol)`< M > & other) const noexcept` <a id="d4/dbe/classsway_1_1core_1_1Symbol_1a57103a1c65e17c588cd9b51c02bb570e"></a>

#### `public inline lpcstr_t `[`getName`](#d4/dbe/classsway_1_1core_1_1Symbol_1a1a5956fdcf863d075adeee18fa758de3)`() const noexcept` <a id="d4/dbe/classsway_1_1core_1_1Symbol_1a1a5956fdcf863d075adeee18fa758de3"></a>

## class `sway::core::Owner` <a id="d8/dba/classsway_1_1core_1_1Owner"></a>

### Summary

 Members | Descriptions 
:---|---
`public virtual  `[`~Owner`](#d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40)`() = default` | 

### Members

#### `public virtual  `[`~Owner`](#d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40)`() = default` <a id="d8/dba/classsway_1_1core_1_1Owner_1ad9dc1eba815866e464cf7e607eb54e40"></a>

## class `sway::core::Enableable` <a id="d0/d00/classsway_1_1core_1_1Enableable"></a>

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

#### `public inline  `[`Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a10cc407dff878c470d9dde858856c10f)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a10cc407dff878c470d9dde858856c10f"></a>

#### `public  `[`~Enableable`](#d0/d00/classsway_1_1core_1_1Enableable_1a67b4ca36f2332bfc76adadb1387241b8)`() = default` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a67b4ca36f2332bfc76adadb1387241b8"></a>

#### `public inline bool `[`enable`](#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04"></a>

Enables the object and returns the previous state.

#### Returns
true - if the object was previously disabled, false - if enabled.

```cpp
auto wasEnabled = enableable.enable();
```

#### `public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550"></a>

Disables the object and returns the previous state.

#### Returns
true - if the object was previously enabled, false - if disabled.

```cpp
auto wasDisabled = enableable.disable();
```

#### `public inline bool `[`isEnabled`](#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1)`() const` <a id="d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1"></a>

Checks if the object is enabled.

#### Returns
true - if the object is enabled, false - if disabled.

#### `public inline void `[`toggle`](#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258"></a>

Switches the state.

## class `sway::core::Nameable` <a id="d9/d81/classsway_1_1core_1_1Nameable"></a>

Helper class with a name.

### Summary

 Members | Descriptions 
:---|---
`public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a2852d732ffa6adae617cfaf32bc8f22b)`(lpcstr_t name)` | 
`public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a76e3941622041bfc4987897aed536ec2)`(const std::string & name)` | 
`public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a7703956e3f3275af40af8f612abb8c79)`(const `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable)` & obj)` | 
`public  `[`~Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a6d15a11034827aead23b4d4e3de4e32f)`() = default` | 
`public inline void `[`setName`](#d9/d81/classsway_1_1core_1_1Nameable_1a552c35cbff377ad3e7ac0e3f143edcb4)`(lpcstr_t name)` | 
`public inline std::string const & `[`getName`](#d9/d81/classsway_1_1core_1_1Nameable_1a87a5713634d27799d712d1aa62ac7ae4)`() const` | 
`public inline bool `[`hasName`](#d9/d81/classsway_1_1core_1_1Nameable_1a86af00cae01fa1f83db33ac3b6e94caa)`() const` | 
`protected std::string `[`name_`](#d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169) | 

### Members

#### `public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a2852d732ffa6adae617cfaf32bc8f22b)`(lpcstr_t name)` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a2852d732ffa6adae617cfaf32bc8f22b"></a>

#### `public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a76e3941622041bfc4987897aed536ec2)`(const std::string & name)` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a76e3941622041bfc4987897aed536ec2"></a>

#### `public inline  `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a7703956e3f3275af40af8f612abb8c79)`(const `[`Nameable`](#d9/d81/classsway_1_1core_1_1Nameable)` & obj)` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a7703956e3f3275af40af8f612abb8c79"></a>

#### `public  `[`~Nameable`](#d9/d81/classsway_1_1core_1_1Nameable_1a6d15a11034827aead23b4d4e3de4e32f)`() = default` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a6d15a11034827aead23b4d4e3de4e32f"></a>

#### `public inline void `[`setName`](#d9/d81/classsway_1_1core_1_1Nameable_1a552c35cbff377ad3e7ac0e3f143edcb4)`(lpcstr_t name)` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a552c35cbff377ad3e7ac0e3f143edcb4"></a>

#### `public inline std::string const & `[`getName`](#d9/d81/classsway_1_1core_1_1Nameable_1a87a5713634d27799d712d1aa62ac7ae4)`() const` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a87a5713634d27799d712d1aa62ac7ae4"></a>

#### `public inline bool `[`hasName`](#d9/d81/classsway_1_1core_1_1Nameable_1a86af00cae01fa1f83db33ac3b6e94caa)`() const` <a id="d9/d81/classsway_1_1core_1_1Nameable_1a86af00cae01fa1f83db33ac3b6e94caa"></a>

#### `protected std::string `[`name_`](#d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169) <a id="d9/d81/classsway_1_1core_1_1Nameable_1a9c3fe779fd4792fd6f3958b6774a0169"></a>

## class `sway::core::Ownable` <a id="d6/d16/classsway_1_1core_1_1Ownable"></a>

Helper class with an owner.

### Summary

 Members | Descriptions 
:---|---
`public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` | 
`public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1)`(const `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable)` & owner)` | 
`public virtual  `[`~Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d)`() = default` | 
`public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` | 
`public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` | 
`public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` | 
`protected `[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) | 

### Members

#### `public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` <a id="d6/d16/classsway_1_1core_1_1Ownable_1a1e72d83475379ec8e4856f47a14225d7"></a>

#### `public inline  `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1)`(const `[`Ownable`](#d6/d16/classsway_1_1core_1_1Ownable)` & owner)` <a id="d6/d16/classsway_1_1core_1_1Ownable_1a96dd6f2af10e492edef03f1f26d442e1"></a>

#### `public virtual  `[`~Ownable`](#d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d)`() = default` <a id="d6/d16/classsway_1_1core_1_1Ownable_1ae327e5de53edf8f1718823905072bf6d"></a>

#### `public void `[`release`](#d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f)`()` <a id="d6/d16/classsway_1_1core_1_1Ownable_1a34bc2be8bbbab412012956e804113b7f"></a>

#### `public inline void `[`setOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c)`(`[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` owner)` <a id="d6/d16/classsway_1_1core_1_1Ownable_1a6cb9796606c490627263a8e0b787e26c"></a>

#### `public inline `[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`getOwner`](#d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c)`() const` <a id="d6/d16/classsway_1_1core_1_1Ownable_1a84c8c053925d97c09c369d5ac1a1c71c"></a>

#### `protected `[`OwnerTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d91/namespacesway_1_1core_1_1OwnerTypedefs_1af3543645d18814d676b8e800f96944c3)` `[`owner_`](#d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4) <a id="d6/d16/classsway_1_1core_1_1Ownable_1a0fbaf77b9972090f7701d0c685f94fe4"></a>

## class `sway::core::Visibleable` <a id="d2/d89/classsway_1_1core_1_1Visibleable"></a>

Helper class for setting and checking the visibility of an object.

### Summary

 Members | Descriptions 
:---|---
`public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` | 
`public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` | 
`public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` | 
`public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` | 

### Members

#### `public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1"></a>

#### `public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11"></a>

#### `public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1"></a>

#### `public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99"></a>

## struct `sway::core::Named` <a id="d0/d2a/structsway_1_1core_1_1Named"></a>

### Summary

 Members | Descriptions 
:---|---
`typedef `[`type_t`](#d0/d2a/structsway_1_1core_1_1Named_1a44fbb5487a1a14610aa70499d1ad30a2) | 

### Members

#### `typedef `[`type_t`](#d0/d2a/structsway_1_1core_1_1Named_1a44fbb5487a1a14610aa70499d1ad30a2) <a id="d0/d2a/structsway_1_1core_1_1Named_1a44fbb5487a1a14610aa70499d1ad30a2"></a>

## struct `sway::core::OwnableDeleter` <a id="d6/da9/structsway_1_1core_1_1OwnableDeleter"></a>

### Summary

 Members | Descriptions 
:---|---
`public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` | 

### Members

#### `public void `[`operator()`](#d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8)`(`[`OwnableTypedefs::Ptr_t`](./generated/md/undefined.md#d1/d26/namespacesway_1_1core_1_1OwnableTypedefs_1a29a12b71a4cb2693846772eb8578d2e1)`< TYPE > obj) const` <a id="d6/da9/structsway_1_1core_1_1OwnableDeleter_1add09b0379b610a273bb9c2e459b0cdb8"></a>

