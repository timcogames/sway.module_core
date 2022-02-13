#ifndef SWAY_CORE_FOUNDATION_OBJECT_HPP
#define SWAY_CORE_FOUNDATION_OBJECT_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context;
class Object {
  public:
    static void registerEmsClass();

    Object(Context *context);

    ~Object() = default;

    void subscribe(Object *sender, const std::string &eventname, AEventHandler *handler);

    void unsubscribe(const std::string &eventname);

    void emit(const std::string &eventname, EventBase *event);

    AEventHandler *findEventHandler(const std::string &eventname);

    [[nodiscard]] auto getUid() { return uniqueid_; }

    void setUid(const std::string &id);

  protected:
    Context *context_; /*!< Контекст. */
    std::vector<AEventHandler *> eventHandlers_; /*!< Обработчики событий. */

  private:
    std::string uniqueid_; /*!< Уникальный идентификатор текущего объекта. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
