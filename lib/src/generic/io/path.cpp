#include <sway/core/generic/io/path.hpp>

#include <algorithm>
#include <fstream>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

Path::Path(const std::string &path)
    : _path(path) {}

auto Path::getFilename() const -> std::string {
  std::string stem;
  size_t position = _path.length() - 1;

  if (_path[position] != '/') {
    stem += _path[position];
  }

  position--;

  while (position >= 0 && _path[position] != '/') {
    stem += _path[position--];
  }

  std::reverse(stem.begin(), stem.end());
  return stem;
}

auto Path::getExt() const -> std::string {
  const std::string &filename = getFilename();
  size_t position = filename.find_last_of(".");

  if (position == std::string::npos) {
    return "";
  }

  return filename.substr(position + 1);
}

auto Path::isExists(const std::string &filename) -> bool {
  bool existed = false;
  std::ifstream file(filename.c_str());
  if (file.good()) {
    existed = true;
  }

  file.close();
  return existed;
}

auto Path::isEmpty() const -> bool { return _path.empty(); }

auto Path::toString() const -> std::string { return _path; }

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)
