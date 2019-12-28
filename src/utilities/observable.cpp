#include <sway/core/utilities/observable.h>
#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(utilities)

Observable::Observable() {
	_observers = std::vector<IObserver *>();
}

Observable::~Observable() {
	_observers.clear();
}

void Observable::registerObserver(IObserver * observer) {
	_observers.push_back(observer);
}

void Observable::removeObserver(IObserver * observer) {
	ObserverArrayIterator_t iter = std::find(_observers.begin(), _observers.end(), observer);
	if (iter != _observers.end())
		_observers.erase(iter);
}

void Observable::notify() {
	for (s32_t i = 0; i < _observers.size(); ++i)
		_observers[i]->update();
}

NAMESPACE_END(utilities)
NAMESPACE_END(core)
NAMESPACE_END(sway)
