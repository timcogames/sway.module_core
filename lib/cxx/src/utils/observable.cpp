#include <sway/core/util/observable.hpp>

namespace sway::core {

Observable::Observable() { observers_ = std::vector<ObserverTypedefs::Ptr_t>(); }

Observable::~Observable() { observers_.clear(); }

void Observable::registerObserver(ObserverTypedefs::Ptr_t obs) { observers_.push_back(obs); }

void Observable::removeObserver(ObserverTypedefs::Ptr_t obs) {
  auto iter = std::find(observers_.begin(), observers_.end(), obs);
  if (iter != observers_.end()) {
    observers_.erase(iter);
  }
}

void Observable::notify() {
  for (auto &obs : observers_) {
    obs->update();
  }
}

}  // namespace sway::core
