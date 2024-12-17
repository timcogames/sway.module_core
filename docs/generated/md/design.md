# group `design` <a id="d9/d1a/group__design"></a>

Various helper classes.

## Summary

 Members | Descriptions 
-|-
`class `[`sway::core::Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable) | 
`class `[`sway::core::Enableable`](#d0/d00/classsway_1_1core_1_1Enableable) | Helper class for enabling/disabling conditional objects.

## class `sway::core::Visibleable` <a id="d2/d89/classsway_1_1core_1_1Visibleable"></a>

### Summary

 Members | Descriptions 
-|-
`public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` | 
`public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` | 
`public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` | 
`public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` | 

### Members

#### `public inline  `[`Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1)`()` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1a05e50830d2c93268765bf847d454fdb1"></a>

#### `public  `[`~Visibleable`](#d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11)`() = default` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1a65e70c9a68db9bdaadf47f516a7b5e11"></a>

#### `public inline void `[`setVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1)`(bool value)` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1ac5e0f7a96f0f3ab7b840e8b2306caed1"></a>

#### `public inline bool `[`isVisible`](#d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99)`() const` <a id="d2/d89/classsway_1_1core_1_1Visibleable_1aa557430e3f7a5f588c222e2623f60d99"></a>

## class `sway::core::Enableable` <a id="d0/d00/classsway_1_1core_1_1Enableable"></a>

Helper class for enabling/disabling conditional objects.

### Summary

 Members | Descriptions 
-|-
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

**See also**: sway::core::misc::disable()

```cpp
auto wasEnabled = enableable.enable();
```

#### `public inline bool `[`disable`](#d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a238fc22ee7102220076cdb6485ac8550"></a>

Disables the object and returns the previous state.

#### Returns
true - if the object was previously enabled, false - if disabled.

**See also**: [enable()](./generated/md/design.md#d0/d00/classsway_1_1core_1_1Enableable_1aa7242264ed11dabc3649109367a4ed04)

```cpp
auto wasDisabled = enableable.disable();
```

#### `public inline bool `[`isEnabled`](#d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1)`() const` <a id="d0/d00/classsway_1_1core_1_1Enableable_1ab6c270115308de16b789aa678c60bdc1"></a>

Checks if the object is enabled.

#### Returns
true - if the object is enabled, false - if disabled.

#### `public inline void `[`toggle`](#d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258)`()` <a id="d0/d00/classsway_1_1core_1_1Enableable_1a71490058dba014bece470ecee9e6f258"></a>

Switches the state.

