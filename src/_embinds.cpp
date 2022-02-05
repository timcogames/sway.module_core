#include <string>

#ifdef _EMSCRIPTEN
	#include <emscripten/bind.h>

	EMSCRIPTEN_BINDINGS(sway_core) {
		emscripten::register_vector<int>("IntegerList");
		emscripten::register_vector<double>("DoubleList");
		emscripten::register_vector<std::string>("StringList");
	}
#endif
