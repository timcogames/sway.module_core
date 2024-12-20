#include <sway/core/misc/_design.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_SHORT(core)

class OwnerTest : public Owner {
public:
  OwnableTypedefs::UniquePtr_t<OwnerTest, OwnableDeleter<OwnerTest>> owner_;
};

TEST(Owner, def) { OwnerTest owner; }
