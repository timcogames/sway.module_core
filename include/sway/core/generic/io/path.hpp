#ifndef _SWAY_CORE_GENERIC_IO_PATH_HPP
#define _SWAY_CORE_GENERIC_IO_PATH_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <vector>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

class Path {
public:
	/*!
	 * \brief
	 *    Конструктор класса по умолчанию.
	 */
	Path(const std::string & path);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Path() = default;

	/*!
	 * \brief
	 *    Возвращает имя файла и расширение.
	 */
	std::string getFilename() const;

	/*!
	 * \brief
	 *    Возвращает расширение файла.
	 */
	std::string getExtension() const;

	bool isExists(const std::string & filename);

	bool isEmpty() const;

	std::string toString() const;

private:
	std::string _path; /*!< Путь к файлу или каталогу. */
};

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_GENERIC_IO_PATH_HPP
