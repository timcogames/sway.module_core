#include <sway/core/util/observable.hpp>

#include <algorithm>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(util)

Observable::Observable() { observers_ = std::vector<Observer::Ptr_t>(); }

Observable::~Observable() { observers_.clear(); }

void Observable::registerObserver(Observer::Ptr_t obs) { observers_.push_back(obs); }

void Observable::removeObserver(Observer::Ptr_t obs) {
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

NS_END()  // namespace util
NS_END()  // namespace core
NS_END()  // namespace sway
