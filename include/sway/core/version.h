#ifndef SWAY_CORE_VERSION_H
#define SWAY_CORE_VERSION_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

class Version {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 * 
	 *    Выполняет инициализацию нового экземпляра класса, приводя к недопустимому объекту Version.
	 */
	Version();
	
	/*!
	 * \brief
	 *    Конструктор класса.
	 * 
	 * \param[in] major
	 *    Главный номер версии.
	 * 
	 * \param[in] minor
	 *    Вспомогательный номер версии.
	 */
	Version(u8_t major, u8_t minor);

	/*!
	 * \brief
	 *    Конструктор копирования.
	 * 
	 * \param[in] version
	 *    Версия, из которой необходимо скопировать данные.
	 */
	Version(const Version & version);

	/*!
	 * \brief
	 *    Конструктор перемещения.
	 * 
	 * \param[in] version
	 *    Версия, из которой необходимо переместить данные.
	 */
	Version(Version && version);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Version() = default;

	/*!
	 * \brief
	 *    Получает главный номер версии.
	 * 
	 * \return
	 *    Главный номер версии.
	 *
	 * \code
	 *    std::cout << static_cast<unsigned>(version.getMajor()) << std::endl;
	 * \endcode
	 */
	u8_t getMajor() const;

	/*!
	 * \brief
	 *    Получает вспомогательный номер версии.
	 * 
	 * \return
	 *    Вспомогательный номер версии.
	 *
	 * \code
	 *    std::cout << static_cast<unsigned>(version.getMinor()) << std::endl;
	 * \endcode
	 */
	u8_t getMinor() const;

	/*!
	 * \brief
	 *    Оператор присваивания другой версии.
	 * 
	 * \param[in] version
	 *    Версия, из которой необходимо скопировать данные.
	 * 
	 * \return
	 *    Ссылка на эту версию.
	 */
	inline Version & operator=(const Version & version);

	/*!
	 * \brief
	 *    Оператор присваивания другой версии.
	 * 
	 * \param[in] version
	 *    Версия, из которой необходимо переместить данные.
	 * 
	 * \return
	 *    Ссылка на эту версию.
	 */
	inline Version & operator=(Version && version);

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия меньше, чем другая версия, иначе 'false'.
	 */
	inline bool operator<(const Version & version) const;

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия больше, чем другая версия, иначе 'false'.
	 */
	inline bool operator>(const Version & version) const;

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия равна другой версии, иначе 'false'.
	 */
	inline bool operator==(const Version & version) const;

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия не равна другой версии, иначе 'false'.
	 */
	inline bool operator!=(const Version & version) const;

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия больше или равна другой версии, иначе 'false'.
	 */
	inline bool operator>=(const Version & version) const;

	/*!
	 * \brief
	 *    Оператор сравнения с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия меньше или равна другой версии, иначе 'false'.
	 */
	inline bool operator<=(const Version & version) const;

private:
	u8_t _major; /*!< Главный номер версии. */
	u8_t _minor; /*!< Вспомогательный номер версии. */
	u8_t _patch;
	u8_t _build;
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/version.inl>

#endif // SWAY_CORE_VERSION_H
