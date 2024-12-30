#include <sway/core.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

class MySubsystem : public Subsystem {
  DECLARE_CLASS_METADATA(MySubsystem, Subsystem)

public:
#pragma region "Ctors/Dtor"

  explicit MySubsystem(ContextTypedefs::Ptr_t ctx)
      : Subsystem(ctx) {}

#pragma endregion

#pragma region "Overridden Subsystem methods"

  MTHD_VIRTUAL_OVERRIDE(bool initialize()) { return true; }

  MTHD_VIRTUAL_OVERRIDE(void tick(float dtm)) {}

  MTHD_VIRTUAL_OVERRIDE(void shutdown()) {}

#pragma endregion
};

class ContextTest : public testing::Test {
public:
#pragma region "Overridden Test methods"

  MTHD_OVERRIDE(void SetUp()) { context_ = new Context(); }

  MTHD_OVERRIDE(void TearDown()) { delete context_; }

#pragma endregion

  ContextTypedefs::Ptr_t context_;
};

TEST_F(ContextTest, get_subsystem) {
  context_->registerSubsystem(std::make_shared<MySubsystem>(context_));
  auto subsystem = context_->getSubsystem<MySubsystem>("MySubsystem");
  EXPECT_NE(subsystem, std::nullopt);
}
