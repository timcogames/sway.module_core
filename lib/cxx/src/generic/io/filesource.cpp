#include <sway/core/generic/io/filesource.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

FileSource::FileSource()
    : opened_(false) {}

auto FileSource::isFileOpened() const -> bool { return opened_; }

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)
