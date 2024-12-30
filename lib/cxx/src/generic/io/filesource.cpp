#include <sway/core/generic/io/filesource.hpp>

namespace sway::core {

FileSource::FileSource()
    : opened_(false) {}

auto FileSource::isFileOpened() const -> bool { return opened_; }

}  // namespace sway::core
