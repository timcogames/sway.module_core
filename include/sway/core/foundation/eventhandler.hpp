#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Object;

/*!
 * \class AEventHandler
 * \brief Описывает обработчик для события.
 */
class AEventHandler {
  public:
    static void registerEmsClass();

    explicit AEventHandler(Object *receiver);

    virtual ~AEventHandler() = default;

    PURE_VIRTUAL(void invoke(EventBase *event));

    Object *getSender() const;

    void setSender(Object *sender);

    Object *getReceiver() const;

    std::string getEventName() const { return eventname_; }

    void setEventName(const std::string &name) { eventname_ = name; }

  protected:
    Object *sender_ = nullptr; /*!< Отправитель события. */
    Object *receiver_; /*!< Слушатель события. */
    std::string uniqueid_; /*!< Уникальный идентификатор, который будет связан с функцией обработчика событий. */
    std::string eventname_; /*!< Название события. */
};

#ifdef _EMSCRIPTEN
class AEventHandlerWrapper : public emscripten::wrapper<AEventHandler> {
  public:
    EMSCRIPTEN_WRAPPER(AEventHandlerWrapper);

    virtual void invoke(EventBase *event) override { return call<void>("invoke", event); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
