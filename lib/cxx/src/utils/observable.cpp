#include <sway/core/util/observable.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(util)

Observable::Observable() { observers_ = std::vector<IObserver::Ptr_t>(); }

Observable::~Observable() { observers_.clear(); }

void Observable::registerObserver(IObserver::Ptr_t observer) { observers_.push_back(observer); }

void Observable::removeObserver(IObserver::Ptr_t observer) {
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

NAMESPACE_END(util)
NAMESPACE_END(core)
NAMESPACE_END(sway)
