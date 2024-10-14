#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeeventdata.hpp>
#include <sway/core/foundation/eventhandlerimpl.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

#include <initializer_list>
#include <memory>
#include <sstream>  // std::stringstream
#include <stdlib.h>  // srand
#include <string>
#include <time.h>  // time
#include <vector>

#define IDX_INTERN_A (0)
#define IDX_INTERN_B (1)
#define IDX_INTERN_C (2)

const std::initializer_list<std::string> InternNameList = {"intern_a", "intern_b", "intern_c"};

NS_SHORT_SWAY()
NS_SHORT(core::container)

class NodeTest : public ::testing::Test, public core::foundation::Eventable {
public:
#pragma region "Ctors/Dtor"

  NodeTest() = default;

  ~NodeTest() = default;

#pragma endregion

#pragma region "Override Subsystem methods"

  MTHD_OVERRIDE(void SetUp()) {
    srand(static_cast<unsigned int>(time(nullptr)));

    root_ = std::make_shared<Node>();
  }

  MTHD_OVERRIDE(void TearDown()) {}

#pragma endregion

  void addSupervisor() {
    supervisor_ = std::make_shared<Node>();
    supervisor_->subscribe(supervisor_.get(), "NodeAdded", EVENT_HANDLER(NodeTest, handleAddNode));
    supervisor_->subscribe(supervisor_.get(), "NodeRemoved", EVENT_HANDLER(NodeTest, handleRemoveNode));
    root_->addChildNode(supervisor_);
  }

  void handleAddNode(core::foundation::Event::Ptr_t evt) {}

  void handleRemoveNode(core::foundation::Event::Ptr_t evt) {}

  void addDoctorToSupervisor() {
    doctor_ = std::make_shared<Node>();
    supervisor_->addChildNode(doctor_);
  }

  void addInternCollectionToDoctor() {
    for (const auto &name : InternNameList) {
      internCollection_.push_back(addInternToDoctor());
    }
  }

  [[nodiscard]]
  auto addInternToDoctor() const -> Node::SharedPtr_t {
    Node::SharedPtr_t intern = std::make_shared<Node>();
    doctor_->addChildNode(intern);
    return intern;
  }

  Node::SharedPtr_t root_;
  Node::SharedPtr_t supervisor_;
  Node::SharedPtr_t doctor_;
  Node::SharedPtrVec_t internCollection_;
};

TEST_F(NodeTest, AddChildNode_Twice_ThatAlreadyHasParent) {
  addSupervisor();
  addDoctorToSupervisor();
  supervisor_->addChildNode(doctor_);
  ASSERT_EQ(supervisor_->getNumOfChildNodes(), 1);
}

TEST_F(NodeTest, add_remove) {
  addSupervisor();
  addDoctorToSupervisor();
  addInternCollectionToDoctor();

  /**
   *    ROOT (-1)
   *    └── SUPERVISOR (0)
   *         └── DOCTOR (0)
   *              ├── INTERN A (0)
   *              ├── INTERN B (1)
   *              └── INTERN C (2)
   */
  ASSERT_EQ(doctor_->getNumOfChildNodes(), 3);

  supervisor_->removeChildNode(doctor_);
  EXPECT_TRUE(internCollection_[IDX_INTERN_B]->getNodeIdx().equal(NodeIdx({NODEIDX_ROOT, IDX_INTERN_B})));

  root_->addChildNode(doctor_);
  EXPECT_TRUE(internCollection_[IDX_INTERN_B]->getNodeIdx().equal(NodeIdx({NODEIDX_ROOT, 1, IDX_INTERN_B})));
}

TEST_F(NodeTest, get_child_node) {
  addSupervisor();
  addDoctorToSupervisor();
  addInternCollectionToDoctor();

  auto internIdx = NodeIdx({NODEIDX_ROOT, 0, 0, IDX_INTERN_C});
  auto intern = doctor_->getChildNode(internIdx);
  EXPECT_TRUE(internIdx.equal(intern->getNodeIdx()));
}

TEST_F(NodeTest, get_child_node__non_existent) {
  addSupervisor();
  addDoctorToSupervisor();
  addInternCollectionToDoctor();

  auto internIdx = NodeIdx({NODEIDX_ROOT, 0, 0, IDX_INTERN_B});
  auto intern = doctor_->getChildNode(internIdx);
  EXPECT_TRUE(internIdx.equal(intern->getNodeIdx()));
}
