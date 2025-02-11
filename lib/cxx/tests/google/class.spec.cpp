#include <sway/core/detail/named.hpp>
#include <sway/core/detail/symbol.hpp>
#include <sway/core/foundation/objectclassmetadata.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

class A : public Super<A> {
public:
  A(const std::string &name) {}

  virtual ~A() = default;
};

class B : public Classable<A, B> {
public:
  B(const std::string &name)
      : Classable<A, B>(name) {}

  virtual ~B() = default;
};

class C : public Classable<B, C> {
public:
  C(const std::string &name)
      : Classable<B, C>(name) {}

  virtual ~C() = default;
};

TEST(Class, get_super_info) {
  auto impl = std::make_shared<C>("test");
  EXPECT_STREQ(impl->getClassName().c_str(), "C");
  EXPECT_STREQ(impl->getSuperInfo()->getClassName().c_str(), "B");
}
