#include <sway/core/detail/named.hpp>
#include <sway/core/detail/symbol.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

class A {
public:
  virtual ~A() = default;
};

class B : public Classable<Super<A>, B> {
public:
  virtual ~B() = default;
};

class C : public Classable<B, C> {
public:
  virtual ~C() = default;
};

TEST(Class, get_super_info) {
  auto impl = std::make_shared<C>();
  EXPECT_STREQ(impl->getClassName().c_str(), "C");
  EXPECT_STREQ(impl->getSuperInfo()->getClassName().c_str(), "B");
}
