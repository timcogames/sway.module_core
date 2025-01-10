#ifndef SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
#define SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/detail/valuedata.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/keywords.hpp>

// clang-format off
#define DECLARE_EVENT(VAR_NAME, EVENT_NAME)                                                                  \
  static FORCE_INLINE const std::string VAR_NAME = #EVENT_NAME;                                              \
  class EVENT_NAME##Event final : public sway::core::Event {                                                 \
  public:                                                                                                    \
    DECLARE_CLASS_METADATA(EVENT_NAME##Event, sway::core::Event)                                             \
    EVENT_NAME##Event(u32_t type, sway::core::EventDataTypedefs::Ptr_t data)                                 \
        : id_(sway::core::newGuid<sway::core::constans::UUID_MAGIC_SIZE>(sway::core::constans::UUID_MAGIC))  \
        , type_(type)                                                                                        \
        , data_(data) {}                                                                                     \
    MTHD_VIRTUAL_OVERRIDE(auto getId() const -> std::string) { return id_; }                                 \
    MTHD_VIRTUAL_OVERRIDE(auto getType() const -> u32_t) { return type_; }                                   \
    MTHD_VIRTUAL_OVERRIDE(auto getData() const -> sway::core::EventDataTypedefs::Ptr_t) { return data_; }    \
                                                                                                             \
  private:                                                                                                   \
    std::string id_;                                                                                         \
    u32_t type_;                                                                                             \
    sway::core::EventDataTypedefs::Ptr_t data_;                                                              \
  };
// clang-format on

#endif  // SWAY_CORE_FOUNDATION_DECLAREEVENTMACROS_HPP
