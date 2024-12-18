#ifndef SWAY_CORE_MISC_DICTIONARY_HPP
#define SWAY_CORE_MISC_DICTIONARY_HPP

#include <sway/core/misc/string.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <string_view>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

namespace DictionaryValueTypedefs {
using Container_t = std::unordered_map<std::string, std::string>;
}  // namespace DictionaryValueTypedefs

class Dictionary {
public:
#pragma region "Static variables"

  static constexpr std::string_view BLANK = "";
  static constexpr std::string_view UNDEF = "undefined";

#pragma endregion

#pragma region "Ctors/Dtor"

  Dictionary() = default;

  DTOR_DEFAULT(Dictionary);

#pragma endregion

  void addString(const std::string &name, const std::string &val) {
    DictionaryValueTypedefs::Container_t::value_type value(name, val);
    variables_.insert(value);
  }

  auto getString(const std::string &name) -> const std::string & {
    static const std::string undef(UNDEF.data(), UNDEF.size());
    const auto iter = variables_.find(name);
    return (iter != variables_.end()) ? iter->second : undef;
  }

  void addInteger(const std::string &name, i32_t val) { addString(name, toString(val)); }

  auto getIntegerOrDefault(const std::string &name, i32_t def) -> i32_t {
    const auto &value = getString(name);
    if (value == BLANK) {
      return def;
    }

    return toInteger(value.c_str(), def);
  }

  void addFloat(const std::string &name, f32_t val) { addString(name, toString(val)); }

  auto getFloatOrDefault(const std::string &name, f32_t def) -> f32_t {
    const auto &value = getString(name);
    if (value == BLANK) {
      return def;
    }

    return toFloat(value.c_str(), def);
  }

  void addBoolean(const std::string &name, bool val) { addString(name, val ? "true" : "false"); }

  auto getBooleanOrDefault(const std::string &name, bool def) -> bool {
    const auto &value = getString(name);
    if (value == BLANK) {
      return def;
    }

    return toBoolean(value.c_str(), def);
  }

private:
  DictionaryValueTypedefs::Container_t variables_;
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_DICTIONARY_HPP
