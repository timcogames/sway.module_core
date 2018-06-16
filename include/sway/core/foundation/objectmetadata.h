#ifndef SWAY_CORE_FOUNDATION_OBJECTMETADATA_H
#define SWAY_CORE_FOUNDATION_OBJECTMETADATA_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string> // std::string

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class ObjectMetadata {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] className
	 *    Имя класса.
	 * 
	 * \param[in] superclass
	 *    Указатель на объект метаданных базового класса.
	 */
	ObjectMetadata(lpcstr_t className, const ObjectMetadata * superclass)
		: _superclass(superclass), _className(className) {

		// Empty
	}

	/*!
	 * \brief
	 *    Получает метаданные базового класса.
	 */
	const ObjectMetadata * getSuperclass() const {
		return _superclass;
	}

	/*!
	 * \brief
	 *    Получает имя класса.
	 */
	const std::string & getClassName() const {
		return _className;
	}

private:
	const ObjectMetadata * _superclass; /*!< Метаданные базового класса. */
	std::string _className; /*!< Имя класса. */
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_FOUNDATION_OBJECTMETADATA_H
