#ifndef SWAY_CORE_FOUNDATION_CONTEXT_HPP
#define SWAY_CORE_FOUNDATION_CONTEXT_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Context {
  public:
    static void registerEmsClass();

    Context();

    ~Context() = default;
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
