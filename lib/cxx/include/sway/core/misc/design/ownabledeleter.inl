#include <sway/core/misc/design/ownable.hpp>

namespace sway::core {

template <typename TYPE>
void OwnableDeleter<TYPE>::operator()(OwnableTypedefs::Ptr_t<TYPE> obj) const {
  obj->release();
}

}  // namespace sway::core
