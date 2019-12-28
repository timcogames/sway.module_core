#ifndef _SWAY_CORE_GENERIC_IO_FILESOURCE_H
#define _SWAY_CORE_GENERIC_IO_FILESOURCE_H

#include <sway/namespacemacros.h>
#include <fstream> // std::ifstream

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

class FileSource {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 */
	FileSource();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~FileSource() = default;

	/*!
	 * \brief
	 *    Последовательное чтение файла.
	 * 
	 * \param[in] source
	 *    Ссылка на поток.
	 */
	virtual void * loadFromStream(std::ifstream & source) = 0;

	/*!
	 * \brief
	 *    Возвращает, открыт ли файл.
	 */
	bool isFileOpened() const;

protected:
	bool _fileOpened; /*!< Открыт ли файл в данный момент. */
};

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_GENERIC_IO_FILESOURCE_H
