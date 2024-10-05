#ifndef SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
#define SWAY_CORE_GENERIC_IO_FILESOURCE_HPP

#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <fstream>  // std::ifstream

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(generic)
NS_BEGIN(io)

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

NS_END()  // namespace io
NS_END()  // namespace generic
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_GENERIC_IO_FILESOURCE_HPP
