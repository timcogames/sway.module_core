#ifndef SWAY_CORE_GENERIC_FILESOURCE_H
#define SWAY_CORE_GENERIC_FILESOURCE_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)

class FileSource {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 */
	FileSource();

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	virtual ~FileSource();

	virtual void * loadFromStream(std::ifstream & source) const = 0;
};

NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_GENERIC_FILESOURCE_H
