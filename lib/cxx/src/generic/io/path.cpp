#include <sway/core/generic/io/path.hpp>

#include <algorithm>
#include <fstream>
#include <unistd.h>  // access

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(generic)
NS_BEGIN(io)

Path::Path(const std::string &path)
    : path_(path) {}

auto Path::getFilename() const -> std::string {
  std::string stem;
  size_t position = path_.length() - 1;

  if (path_[position] != '/') {
    stem += path_[position];
  }

  position--;

  while (position >= 0 && path_[position] != '/') {
    stem += path_[position--];
  }

  std::reverse(stem.begin(), stem.end());
  return stem;
}

auto Path::getExt() const -> std::string {
  const auto &filename = getFilename();
  size_t position = filename.find_last_of(".");

  if (position == std::string::npos) {
    return "";
  }

  return filename.substr(position + 1);
}

auto Path::isFileExists(const std::string &filename) const -> bool {
  auto const mode = 0;  // проверяет существование файла
  return access(filename.c_str(), mode) == 0;
}

auto Path::isExists(const std::string &filename) const -> bool {
  auto existed = false;
  std::ifstream file(filename.c_str());
  if (file.good()) {
    existed = true;
  }

  file.close();
  return existed;
}

auto Path::isEmpty() const -> bool { return path_.empty(); }

auto Path::toString() const -> std::string { return path_; }

NS_END()  // namespace io
NS_END()  // namespace generic
NS_END()  // namespace core
NS_END()  // namespace sway
