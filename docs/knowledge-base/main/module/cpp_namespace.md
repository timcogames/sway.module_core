
###### По умолчанию:

```
namespace sway::NAME {

...

} // namespace sway::NAME
```

###### На макросах (deprecated):

```
/**
 * @namespace sway::NAME
 * {@
 */

NS_BEGIN_SWAY()
NS_BEGIN(NAME)

...

NS_END() // namespace NAME
NS_END() // namespace sway

/**
 * ends namespace
 * @}
 */
```