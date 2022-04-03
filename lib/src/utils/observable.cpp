#include <sway/core/utils/observable.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

Observable::Observable() { observers_ = std::vector<IObserver *>(); }

Observable::~Observable() { observers_.clear(); }

void Observable::registerObserver(IObserver *observer) { observers_.push_back(observer); }

void Observable::removeObserver(IObserver *observer) {
  auto iter = std::find(observers_.begin(), observers_.end(), observer);
  if (iter != observers_.end()) {
    observers_.erase(iter);
  }
}

void Observable::notify() {
  for (auto &observer : observers_) {
    observer->update();
  }
}

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)
