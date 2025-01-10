#ifndef SWAY_CORE_FOUNDATION_OBJECTCLASSNAME_HPP
#define SWAY_CORE_FOUNDATION_OBJECTCLASSNAME_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

class ObjectClassName {
public:
  static auto demangle(lpcstr_t name) -> std::string {
    i32_t status;
    std::unique_ptr<s8_t, void (*)(void *)> result{abi::__cxa_demangle(name, 0, 0, &status), std::free};

    return (status == 0) ? result.get() : name;
  }

  template <typename T>
  static auto toStr() -> std::string {
    std::string classname = ObjectClassName::demangle(typeid(T).name());
    std::string delimiter = "::";

    return classname.substr(classname.rfind(delimiter) + 2);
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_OBJECTCLASSNAME_HPP
