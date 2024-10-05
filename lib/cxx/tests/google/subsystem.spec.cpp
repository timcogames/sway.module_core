#include <sway/core.hpp>

#include <gtest/gtest.h>

#include <memory>

NS_SHORT_SWAY()
NS_SHORT(core)

class MySubsystem : public foundation::Subsystem {
  DECLARE_CLASS_METADATA(MySubsystem, foundation::Subsystem)

public:
#pragma region "Ctors/Dtor"

  explicit MySubsystem(foundation::Context::Ptr_t ctx)
      : foundation::Subsystem(ctx) {}

#pragma endregion

#pragma region "Override Subsystem methods"

  MTHD_VIRTUAL_OVERRIDE(bool initialize()) { return true; }

  MTHD_VIRTUAL_OVERRIDE(void tick(float dtm)) {}

  MTHD_VIRTUAL_OVERRIDE(void shutdown()) {}

#pragma endregion
};

class ContextTest : public testing::Test {
public:
#pragma region "Override Test methods"

  MTHD_OVERRIDE(void SetUp()) { context_ = new foundation::Context(); }

  MTHD_OVERRIDE(void TearDown()) { delete context_; }

#pragma endregion

  foundation::Context::Ptr_t context_;
};

TEST_F(ContextTest, get_subsystem) {
  context_->registerSubsystem(std::make_shared<MySubsystem>(context_));
  auto subsystem = context_->getSubsystem<MySubsystem>("MySubsystem");
  EXPECT_NE(subsystem, std::nullopt);
}
