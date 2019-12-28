#ifndef _SWAY_CORE_H
#define _SWAY_CORE_H

#include <sway/core/utilities/observer.h>
#include <sway/core/utilities/observable.h>
#include <sway/core/utilities/visitor.h>
#include <sway/core/utilities/visitable.h>
#include <sway/core/misc/format.h>
#include <sway/core/misc/guid.h>
#include <sway/core/containers/hierarchylistener.h>
#include <sway/core/containers/hierarchynode.h>
#include <sway/core/containers/hierarchy.h>
#include <sway/core/runtime/exception.h>
#include <sway/core/runtime/exceptions/argumentnullexception.h>
#include <sway/core/runtime/exceptions/librarynotfoundexception.h>
#include <sway/core/runtime/exceptions/symbolnotfoundexception.h>
#include <sway/core/detail/rawtype.h>
#include <sway/core/detail/datatypes.h>
#include <sway/core/detail/enumutils.h>
#include <sway/core/foundation/objectmetadata.h>
#include <sway/core/foundation/object.h>
#include <sway/core/foundation/declareobjectmacros.h>
#include <sway/core/foundation/context.h>
#include <sway/core/binding/procaddress.h>
#include <sway/core/binding/function.h>
#include <sway/core/generic/io/path.h>
#include <sway/core/generic/io/filesource.h>
#include <sway/core/intrusive/priorities.h>
#include <sway/core/memory/safedeletemacros.h>
#include <sway/core/version.h>
#include <sway/core/plugininfo.h>
#include <sway/core/plugin.h>
#include <sway/namespacemacros.h>
#include <sway/visibilitymacros.h>
#include <sway/defines.h>
#include <sway/types.h>

#endif // _SWAY_CORE_H
