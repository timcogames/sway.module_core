#include <sway/core/generic/io/filesource.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(generic)
NS_BEGIN(io)

FileSource::FileSource()
    : opened_(false) {}

auto FileSource::isFileOpened() const -> bool { return opened_; }

NS_END()  // namespace io
NS_END()  // namespace generic
NS_END()  // namespace core
NS_END()  // namespace sway
