#ifndef SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
#define SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

#define DECLARE_EVENT(EventId, EventName)                                   \
  static inline const std::string EventId = #EventName;                     \
  class EventName##Event final : public sway::core::foundation::Event {     \
  public:                                                                   \
    DECLARE_CLASS_METADATA(EventName##Event, sway::core::foundation::Event) \
    EventName##Event(u32_t type, void *data)                                \
        : id_(sway::core::misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))    \
        , type_(type)                                                       \
        , data_(data) {}                                                    \
    MTHD_OVERRIDE(std::string id() const) { return id_; }                   \
    MTHD_OVERRIDE(u32_t type() const) { return type_; }                     \
    MTHD_OVERRIDE(void *data() const) { return data_; }                     \
                                                                            \
  private:                                                                  \
    std::string id_;                                                        \
    u32_t type_;                                                            \
    void *data_;                                                            \
  };

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
