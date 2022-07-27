#ifndef SWAY_CORE_FOUNDATION_OBJECT_HPP
#define SWAY_CORE_FOUNDATION_OBJECT_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context;
class Object {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  Object(Context *context);

  ~Object() = default;

  [[nodiscard]] auto getUid() { return uniqueid_; }

  void setUid(const std::string &id);

protected:
  Context *context_; /*!< Контекст. */

private:
  std::string uniqueid_; /*!< Уникальный идентификатор текущего объекта. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
