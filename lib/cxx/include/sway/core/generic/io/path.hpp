#ifndef SWAY_CORE_GENERIC_IO_PATH_HPP
#define SWAY_CORE_GENERIC_IO_PATH_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

class Path {
public:
  Path(const std::string &path);

  ~Path() = default;

  [[nodiscard]] auto getFilename() const -> std::string;

  [[nodiscard]] auto getExt() const -> std::string;

  [[nodiscard]] auto isExists(const std::string &filename) const -> bool;

  [[nodiscard]] auto isEmpty() const -> bool;

  [[nodiscard]] auto toString() const -> std::string;

private:
  std::string path_;  // Путь к файлу или каталогу.
};

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_GENERIC_IO_PATH_HPP
