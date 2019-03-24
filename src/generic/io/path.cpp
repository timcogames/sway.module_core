#include <sway/core/generic/io/path.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(generic)
NAMESPACE_BEGIN(io)

Path::Path() {
	// Empty
}

std::string Path::getFileName() const {
	if (_path.empty())
		return "";

	return _path[_path.size() - 1];
}

std::string Path::getExtension() const {
	const std::string & name = getFileName();
	size_t position = name.find_last_of(".");
	
	if (position == std::string::npos)
		return "";

	return name.substr(position + 1);
}

NAMESPACE_END(io)
NAMESPACE_END(generic)
NAMESPACE_END(core)
NAMESPACE_END(sway)
