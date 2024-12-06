#ifndef SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
#define SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP

#include <sway/core/detail/valuedata.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

// clang-format off
#define DECLARE_EVENT(VAR_NAME, EVENT_NAME)                                                                \
  static FORCE_INLINE const std::string VAR_NAME = #EVENT_NAME;                                            \
  class EVENT_NAME##Event final : public sway::core::foundation::Event {                                   \
  public:                                                                                                  \
    DECLARE_CLASS_METADATA(EVENT_NAME##Event, sway::core::foundation::Event)                               \
    EVENT_NAME##Event(u32_t type, sway::core::foundation::EventData::Ptr_t data)                           \
        : id_(sway::core::misc::newGuid<UUID_NBR_OF_GROUPS>(UUID_MAGIC))                                   \
        , type_(type)                                                                                      \
        , data_(data) {}                                                                                   \
    MTHD_VIRTUAL_OVERRIDE(auto id() const -> std::string) { return id_; }                                  \
    MTHD_VIRTUAL_OVERRIDE(auto type() const -> u32_t) { return type_; }                                    \
    MTHD_VIRTUAL_OVERRIDE(auto data() const -> sway::core::foundation::EventData::Ptr_t) { return data_; } \
                                                                                                           \
  private:                                                                                                 \
    std::string id_;                                                                                       \
    u32_t type_;                                                                                           \
    sway::core::foundation::EventData::Ptr_t data_;                                                        \
  };
// clang-format on

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
