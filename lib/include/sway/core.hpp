#ifndef SWAY_CORE_HPP
#define SWAY_CORE_HPP

#include <sway/core/binding/function.hpp>
#include <sway/core/binding/procaddress.hpp>
#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/detail/datatypes.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/rawtype.hpp>
#include <sway/core/foundation/context.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/foundation/eventhandlerimpl.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/generic/io/filesource.hpp>
#include <sway/core/generic/io/path.hpp>
#include <sway/core/intrusive/priorities.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/misc/uid.hpp>
#include <sway/core/plugin.hpp>
#include <sway/core/plugininfo.hpp>
#include <sway/core/runtime/exception.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/core/runtime/exceptions/librarynotfoundexception.hpp>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.hpp>
#include <sway/core/utils/observable.hpp>
#include <sway/core/utils/observer.hpp>
#include <sway/core/utils/traverser.hpp>
#include <sway/core/utils/visitable.hpp>
#include <sway/core/version.hpp>
#include <sway/defines.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

#endif
