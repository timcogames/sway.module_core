#include <sway/core.hpp>

#include <gtest/gtest.h>

#include <memory>

using namespace sway;
using namespace sway::core;

class MySubsystem : public foundation::Subsystem {
public:
  DECLARE_CLASS_METADATA(MySubsystem, foundation::Subsystem)

  explicit MySubsystem(foundation::Context *ctx)
      : foundation::Subsystem(ctx) {}

  MTHD_OVERRIDE(bool initialize()) { return true; }

  MTHD_OVERRIDE(void tick(float timestep)) {}

  MTHD_OVERRIDE(void shutdown()) {}
};

class ContextTest : public testing::Test {
public:
  MTHD_OVERRIDE(void SetUp()) { context_ = new foundation::Context(); }

  MTHD_OVERRIDE(void TearDown()) { delete context_; }

  foundation::Context *context_;
};

TEST_F(ContextTest, setRootNode) {
  context_->registerSubsystem(std::make_shared<MySubsystem>(context_));
  auto subsystem = context_->getSubsystem<MySubsystem>("MySubsystem");
  EXPECT_NE(subsystem, std::nullopt);
}
