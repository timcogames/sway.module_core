#include <sway/core/containers/nodeidx.h>
#include <string> // std::string

NAMESPACE_BEGIN(std)

template<typename TYPE>
inline string to_string(const sway::core::containers::NodeIdx & nodeIdx) {
	std::string str = "[";
	for (sway::u32_t i = 0; i < nodeIdx.getDepth(); ++i) {
		str += std::to_string(nodeIdx.getIdxAt(i));
		if (i < nodeIdx.getDepth() - 1)
			str += ", ";
	}
	str += "]";

	return str;
}

NAMESPACE_END(std)
