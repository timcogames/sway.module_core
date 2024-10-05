#ifndef SWAY_CORE_GENERIC_IO_PATH_HPP
#define SWAY_CORE_GENERIC_IO_PATH_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(generic)
NS_BEGIN(io)

class Path {
public:
#pragma region "Ctors/Dtor"

  Path(const std::string &path);

  ~Path() = default;

#pragma endregion

  [[nodiscard]]
  auto getFilename() const -> std::string;

  [[nodiscard]]
  auto getExt() const -> std::string;

  [[nodiscard]]
  auto isFileExists(const std::string &filename) const -> bool;

  [[nodiscard]]
  auto isExists(const std::string &filename) const -> bool;

  [[nodiscard]]
  auto isEmpty() const -> bool;

  [[nodiscard]]
  auto toString() const -> std::string;

private:
  std::string path_;  // Путь к файлу или каталогу.
};

NS_END()  // namespace io
NS_END()  // namespace generic
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_GENERIC_IO_PATH_HPP
