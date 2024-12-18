#ifndef SWAY_CORE_HPP
#define SWAY_CORE_HPP

/**
 * @namespace sway::core
 * \~russian @brief Корневое пространство имен данной библиотеки.
 *
 * \~english @brief Root namespace of this library.
 */

#include <sway/core/binding/function.hpp>
#include <sway/core/binding/procaddress.hpp>
#include <sway/core/container/hierarchy.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodedata.hpp>
#include <sway/core/container/nodeeventdata.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/container/types.hpp>
#include <sway/core/detail/enumclassbitset.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/rawtype.hpp>
#include <sway/core/detail/valuedata.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/core/events/eventbus.hpp>
#include <sway/core/events/eventhandler.hpp>
#include <sway/core/events/subscribable.hpp>
#include <sway/core/foundation/callbackmacros.hpp>
#include <sway/core/foundation/context.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventactionmapper.hpp>
#include <sway/core/foundation/eventapplier.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/foundation/eventhandlerimpl.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/core/foundation/uniqueable.hpp>
#include <sway/core/generic/io/filesource.hpp>
#include <sway/core/generic/io/path.hpp>
#include <sway/core/intrusive/priorities.hpp>
#include <sway/core/memory/pointercast.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/core/util/traverseractions.hpp>
#include <sway/pointermacros.hpp>
// #include <sway/core/misc/optional.hpp>
#include <sway/core/misc/_design.hpp>
#include <sway/core/misc/atomicidgen.hpp>
#include <sway/core/misc/atomicidgenbuffer.hpp>
#include <sway/core/misc/atomicidgenmanager.hpp>
#include <sway/core/misc/dictionary.hpp>
#include <sway/core/misc/hash.hpp>
#include <sway/core/misc/string.hpp>
#include <sway/core/plugin.hpp>
#include <sway/core/plugininfo.hpp>
#include <sway/core/runtime/exception.hpp>
#include <sway/core/runtime/exceptions/argumentnullexception.hpp>
#include <sway/core/runtime/exceptions/librarynotfoundexception.hpp>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.hpp>
#include <sway/core/time/chronounits.hpp>
#include <sway/core/time/clock.hpp>
#include <sway/core/time/duration.hpp>
#include <sway/core/time/timepoint.hpp>
#include <sway/core/time/timer.hpp>
#include <sway/core/time/timerstatus.hpp>
#include <sway/core/time/timerutil.hpp>
#include <sway/core/util/observable.hpp>
#include <sway/core/util/observer.hpp>
#include <sway/core/util/traverser.hpp>
#include <sway/core/util/typedefs.hpp>
#include <sway/core/util/visitable.hpp>
#include <sway/core/version.hpp>
#include <sway/defines.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/enumeratormacros.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

#endif  // SWAY_CORE_HPP
