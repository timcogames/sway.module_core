#ifndef SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
#define SWAY_CORE_GENERIC_IO_FILESOURCE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <fstream>  // std::ifstream

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

class FileSource {
public:
#pragma region "Ctors/Dtor"

  FileSource();

  virtual ~FileSource() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto loadFromStream(std::ifstream &source) -> void *);

#pragma endregion

  [[nodiscard]]
  auto isFileOpened() const -> bool;

protected:
  bool opened_;  // Открыт ли файл в данный момент.
};

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
