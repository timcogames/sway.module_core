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

// clang-format off
#define DECLARE_EVENT(VAR_NAME, EVENT_NAME)                                                   \
  static inline const std::string VAR_NAME = #EVENT_NAME;                                     \
  class EVENT_NAME##Event final : public sway::core::foundation::Event {                      \
  public:                                                                                     \
    DECLARE_CLASS_METADATA(EVENT_NAME##Event, sway::core::foundation::Event)                  \
    EVENT_NAME##Event(u32_t type, sway::core::foundation::EventData *data)                    \
        : id_(sway::core::misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))                      \
        , type_(type)                                                                         \
        , data_(data) {}                                                                      \
    MTHD_OVERRIDE(auto id() const -> std::string) { return id_; }                             \
    MTHD_OVERRIDE(auto type() const -> u32_t) { return type_; }                               \
    MTHD_OVERRIDE(auto data() const -> sway::core::foundation::EventData *) { return data_; } \
                                                                                              \
  private:                                                                                    \
    std::string id_;                                                                          \
    u32_t type_;                                                                              \
    sway::core::foundation::EventData *data_;                                                 \
  };
// clang-format on

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
