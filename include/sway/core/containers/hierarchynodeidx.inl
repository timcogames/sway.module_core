#include <sway/core/containers/hierarchynodeidx.h>

#include <string> // std::string
#include <iostream> // std::ostream
#include <sstream> // std::stringstream

NAMESPACE_BEGIN(std)

template<typename TYPE>
inline string to_string(const sway::core::containers::HierarchyNodeIdx & nodeIdx) {
	stringstream stream;
	stream << "[";
	for (int i = 0; i < nodeIdx.getDepth(); ++i) {
		stream << std::to_string(nodeIdx.getIdxAt(i));
		if (i < nodeIdx.getDepth() - 1)
			stream << ", ";
	}
	stream << "]";

	return stream.str();
}

NAMESPACE_END(std)
