#include <sway/core/utils/observable.h>
#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utils)

Observable::Observable() {
	observers_ = std::vector<IObserver *>();
}

Observable::~Observable() {
	observers_.clear();
}

void Observable::registerObserver(IObserver * observer) {
	observers_.push_back(observer);
}

void Observable::removeObserver(IObserver * observer) {
	ObserverArrayIterator_t iter = std::find(observers_.begin(), observers_.end(), observer);
	if (iter != observers_.end())
		observers_.erase(iter);
}

void Observable::notify() {
	for (s32_t i = 0; i < observers_.size(); ++i)
		observers_[i]->update();
}

NAMESPACE_END(utils)
NAMESPACE_END(core)
NAMESPACE_END(sway)
