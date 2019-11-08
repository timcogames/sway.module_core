#ifndef SWAY_CORE_CONTAINERS_HIERARCHY_H
#define SWAY_CORE_CONTAINERS_HIERARCHY_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string>
#include <map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

template<typename TYPE>
class THierarchy {
public:
	THierarchy(const std::string & name)
		: _name(name) {
		// Empty
	}

	~THierarchy() {
		// Empty
	}

	void addChild(TYPE * child) {
		children.insert(std::make_pair(child->getName(), child));
		child->setParent(static_cast<TYPE *>(this));
	}

	void removeChild(TYPE * child) {
		typename NodeMap_t::const_iterator iter = children.find(child->getName());
		if (iter != children.end() && iter->second == child) {
			children.erase(iter);
			child->setParent(nullptr);
		}
	}

	void removeAll() {
		for (typename NodeMap_t::const_iterator iter = children.begin(); iter != children.end(); ++iter) {
			TYPE * object = iter->second;
			object->setParent(nullptr);
			delete object;
		}

		children.clear();
	}

	TYPE * findChild(const std::string & name) {
		typename NodeMap_t::const_iterator iter = children.find(name);
		if (iter != children.end())
			return iter->second;

		return nullptr;
	}

	u32_t getChildCount() {
		return static_cast<u32_t>(children.size());
	}

	void setParent(TYPE * parent) {
		_parent = parent;
	}

	/*!
	 * \brief
	 *    Возвращает родительский узел.
	 */
	TYPE * getParent() {
		return _parent;
	}

	void setName(const std::string & name) {
		_name = name;
	}

	std::string getName() const {
		return _name;
	}

protected:
	typedef std::map<std::string, TYPE *> NodeMap_t;
	NodeMap_t children;

private:
	TYPE * _parent;
	std::string _name;
};

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_CONTAINERS_HIERARCHY_H
