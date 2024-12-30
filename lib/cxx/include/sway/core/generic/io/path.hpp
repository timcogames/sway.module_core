#ifndef SWAY_CORE_GENERIC_IO_PATH_HPP
#define SWAY_CORE_GENERIC_IO_PATH_HPP

#include <sway/_stdafx.hpp>
#include <sway/types.hpp>

namespace sway::core {

class Path {
public:
#pragma region "Ctors/Dtor"

  Path(const std::string &path);

  ~Path() = default;

#pragma endregion

  [[nodiscard]] auto getFilename() const -> std::string;

  [[nodiscard]] auto getExt() const -> std::string;

  [[nodiscard]] auto isFileExists(const std::string &filename) const -> bool;

  [[nodiscard]] auto isExists(const std::string &filename) const -> bool;

  [[nodiscard]] auto isEmpty() const -> bool;

  [[nodiscard]] auto toString() const -> std::string;

private:
  std::string path_;  // Путь к файлу или каталогу.
};

}  // namespace sway::core

#endif  // SWAY_CORE_GENERIC_IO_PATH_HPP
