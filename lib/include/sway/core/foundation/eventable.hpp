#ifndef SWAY_CORE_FOUNDATION_EVENTABLE_HPP
#define SWAY_CORE_FOUNDATION_EVENTABLE_HPP

#include <sway/core/foundation/eventhandler.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <functional>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

using EmitPredicate_t = std::function<bool(AEventHandler *)>;

class Eventable {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  Eventable() = default;

  ~Eventable() = default;

  void subscribe(Eventable *sender, const std::string &eventname, AEventHandler *handler);

  void unsubscribe(const std::string &eventname);

  void emit(const std::string &eventname, Event *event, EmitPredicate_t predicate);

  AEventHandler *findEventHandler(const std::string &eventname);

protected:
  std::vector<AEventHandler *> eventHandlers_; /*!< Обработчики событий. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
