#ifndef SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
#define SWAY_CORE_GENERIC_IO_FILESOURCE_HPP

#include <sway/_stdafx.hpp>

namespace sway::core {

class FileSource {
public:
#pragma region "Ctors/Dtor"

  FileSource();

  virtual ~FileSource() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto loadFromStream(std::ifstream &source) -> void * = 0;

#pragma endregion

  [[nodiscard]] auto isFileOpened() const -> bool;

protected:
  bool opened_;  //!< \~english Is file opened. \~russian Открыт ли файл в данный момент.
};

}  // namespace sway::core

#endif  // SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
