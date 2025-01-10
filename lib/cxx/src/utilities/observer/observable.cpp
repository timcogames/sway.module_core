#include <sway/core/utilities/observer/observable.hpp>

namespace sway::core {

Observable::Observable() { observers_ = std::vector<typedefs::ObserverPtr_t>(); }

Observable::~Observable() { observers_.clear(); }

void Observable::addObserver(typedefs::ObserverPtr_t obs) { observers_.push_back(obs); }

void Observable::removeObserver(typedefs::ObserverPtr_t obs) {
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
