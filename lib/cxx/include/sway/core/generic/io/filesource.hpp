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
  FileSource();

  virtual ~FileSource() = default;

  PURE_VIRTUAL(void *loadFromStream(std::ifstream &source));

  [[nodiscard]] auto isFileOpened() const -> bool;

protected:
  bool _fileOpened;  // Открыт ли файл в данный момент.
};

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
