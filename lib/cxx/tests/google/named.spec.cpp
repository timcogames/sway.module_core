#include <sway/core/detail/named.hpp>
#include <sway/core/detail/symbol.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

TEST(Named, def) {
  static constexpr const s8_t intSymbol[] = "int";
  Named<i32_t, 4, intSymbol> intSymbolNamed;
  EXPECT_STREQ(intSymbolNamed.nameCStr, "int");

  static constexpr const s8_t boolSymbol[] = "bool";
  Named<bool, 5, boolSymbol> boolSymbolNamed;
  EXPECT_STREQ(boolSymbolNamed.nameCStr, "bool");
}
