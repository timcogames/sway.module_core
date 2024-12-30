#ifndef SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
#define SWAY_CORE_GENERIC_IO_FILESOURCE_HPP

#include <sway/_stdafx.hpp>
#include <sway/keywords.hpp>

namespace sway::core {

class FileSource {
public:
#pragma region "Ctors/Dtor"

  FileSource();

  virtual ~FileSource() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto loadFromStream(std::ifstream &source) -> void *);

#pragma endregion

  [[nodiscard]] auto isFileOpened() const -> bool;

protected:
  bool opened_;  // Открыт ли файл в данный момент.
};

}  // namespace sway::core

#endif  // SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
