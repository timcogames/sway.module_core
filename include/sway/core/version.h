#ifndef _SWAY_CORE_VERSION_H
#define _SWAY_CORE_VERSION_H

#include <sway/namespacemacros.h>
#include <sway/defines.h>
#include <sway/types.h>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

/*!
 * \brief
 *    Класс для хранения информации о версии.
 */
class Version {
public:

#pragma region "Constructors / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 *    Выполняет инициализацию нового экземпляра класса, приводя к недопустимому объекту Version.
	 *
	 * \sa
	 *    Version(s32_t, s32_t, s32_t, lpcstr_t)
	 *    Version(const Version &)
	 *    Version(Version &&)
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
	 * 
	 * \param[in] patch
	 *    Уровень исправлений.
	 * 
	 * \sa
	 *    Version()
	 *    Version(const Version &)
	 *    Version(Version &&)
	 */
	Version(s32_t major, s32_t minor = DONT_CARE, s32_t patch = DONT_CARE, lpcstr_t extra = "\0");

	/*!
	 * \brief
	 *    Конструктор копирования.
	 * 
	 * \param[in] version
	 *    Версия, из которой необходимо скопировать данные.
	 * 
	 * \sa
	 *    Version()
	 *    Version(s32_t, s32_t, s32_t, lpcstr_t)
	 *    Version(Version &&)
	 */
	Version(const Version & version);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Version() = default;

#pragma endregion // Constructors / Destructor

#pragma region "Setter / Getter Major"

	/*!
	 * \brief
	 *    Устанавливает главный номер версии.
	 * 
	 * \param[in] major
	 *    Главный номер версии.
	 * 
	 * \sa
	 *    setMinor(s32_t)
	 *    setPatch(s32_t)
	 *    setExtra(lpcstr_t)
	 */
	void setMajor(s32_t major) {
		_major = major;
	}

	/*!
	 * \brief
	 *    Получает главный номер версии.
	 * 
	 * \sa
	 *    getMinor() const
	 *    getPatch() const
	 *    getExtra() const
	 */
	s32_t getMajor() const {
		return _major;
	}

#pragma endregion // Setter / Getter Major

#pragma region "Setter / Getter Minor"

	/*!
	 * \brief
	 *    Устанавливает вспомогательный номер версии.
	 * 
	 * \param[in] minor
	 *    Вспомогательный номер версии.
	 * 
	 * \sa
	 *    setMajor(s32_t)
	 *    setPatch(s32_t)
	 *    setExtra(lpcstr_t)
	 */
	void setMinor(s32_t minor) {
		_minor = minor;
	}

	/*!
	 * \brief
	 *    Получает вспомогательный номер версии.
	 * 
	 * \sa
	 *    getMajor() const
	 *    getPatch() const
	 *    getExtra() const
	 */
	s32_t getMinor() const {
		return _minor;
	}

#pragma endregion // Setter / Getter Minor

#pragma region "Setter / Getter Patch Level"

	/*!
	 * \brief
	 *    Устанавливает уровень исправлений.
	 * 
	 * \param[in] patch
	 *    Уровень исправлений.
	 * 
	 * \sa
	 *    setMajor(s32_t)
	 *    setMinor(s32_t)
	 *    setExtra(lpcstr_t)
	 */
	void setPatch(s32_t patch) {
		_patch = patch;
	}

	/*!
	 * \brief
	 *    Получает уровень исправлений.
	 * 
	 * \sa
	 *    getMajor() const
	 *    getMinor() const
	 *    getExtra() const
	 */
	s32_t getPatch() const {
		return _patch;
	}

#pragma endregion // Setter / Getter Patch Level

#pragma region "Setter / Getter Extra"

	/*!
	 * \brief
	 *    Устанавливает дополнительные символы.
	 * 
	 * \param[in] extra
	 *    Дополнительные символы.
	 * 
	 * \sa
	 *    setMajor(s32_t)
	 *    setMinor(s32_t)
	 *    setPatch(s32_t)
	 */
	void setExtra(lpcstr_t extra) {
		_extra = extra;
	}

	/*!
	 * \brief
	 *    Получает дополнительные символы.
	 * 
	 * \sa
	 *    getMajor() const
	 *    getMinor() const
	 *    getPatch() const
	 */
	std::string getExtra() const {
		return _extra;
	}

#pragma endregion // Setter / Getter Extra

	/*!
	 * \brief
	 *    Сравнение версии.
	 * 
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
	 * 
	 * \param[in] version
	 *    Версия, с которой следует сравнить.
	 */
	s32_t compare(const Version & version) const;

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
	 *    Оператор сравнения с другой версией.
	 * 
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
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
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
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
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
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
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
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
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
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
	 * \note
	 *    Дополнительные символы не участвуют при сравнении с другой версией.
	 * 
	 * \param[in] version
	 *    Версия для сравнения.
	 * 
	 * \return
	 *    Значение 'true', если эта версия меньше или равна другой версии, иначе 'false'.
	 */
	inline bool operator<=(const Version & version) const;

private:
	s32_t _major; /*!< Главный номер версии. */
	s32_t _minor; /*!< Вспомогательный номер версии. */
	s32_t _patch; /*!< Уровень исправлений. */
	std::string _extra; /*!< Дополнительные символы. */
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#include <sway/core/version.inl>

#endif // _SWAY_CORE_VERSION_H
