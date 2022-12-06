#include <sway/core/generic/io/filesource.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

FileSource::FileSource()
    : _fileOpened(false) {}

auto FileSource::isFileOpened() const -> bool { return _fileOpened; }

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)
