#include <sway/core/container/node.hpp>
#include <sway/keywords.hpp>

#include <gtest/gtest.h>

#include <sstream>  // std::stringstream

#define IDX_INTERN_A (0)
#define IDX_INTERN_B (1)
#define IDX_INTERN_C (2)

const std::initializer_list<std::string> InternNameList = {"intern_a", "intern_b", "intern_c"};

using namespace sway::core::container;

class NodeTest : public ::testing::Test {
  public:
    NodeTest() {}

    ~NodeTest() = default;

    MTHD_OVERRIDE(void SetUp()) {
        srand(static_cast<unsigned int>(time(nullptr)));

        root_ = std::make_shared<Node>();
    }

    MTHD_OVERRIDE(void TearDown()) {}

    void addSupervisor() {
        supervisor_ = std::make_shared<Node>();
        root_->addChildNode(supervisor_);
    }

    void addDoctorToSupervisor() {
        doctor_ = std::make_shared<Node>();
        supervisor_->addChildNode(doctor_);
    }

    void addInternCollectionToDoctor() {
        for (const auto &name : InternNameList) {
            internCollection_.push_back(addInternToDoctor());
        }
    }

    std::shared_ptr<Node> addInternToDoctor() {
        std::shared_ptr<Node> intern = std::make_shared<Node>();
        doctor_->addChildNode(intern);
        return intern;
    }

    std::shared_ptr<Node> root_;
    std::shared_ptr<Node> supervisor_;
    std::shared_ptr<Node> doctor_;
    std::vector<std::shared_ptr<Node>> internCollection_;
};

TEST_F(NodeTest, AddChildNode_Twice_ThatAlreadyHasParent) {
    addSupervisor();
    addDoctorToSupervisor();
    supervisor_->addChildNode(doctor_);
    ASSERT_EQ(supervisor_->getNumOfChildNodes(), 1);
}

TEST_F(NodeTest, AddRemove) {
    addSupervisor();
    addDoctorToSupervisor();
    addInternCollectionToDoctor();

    /*!
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

TEST_F(NodeTest, GetChildNode) {
    addSupervisor();
    addDoctorToSupervisor();
    addInternCollectionToDoctor();

    auto internIdx = NodeIdx({NODEIDX_ROOT, 0, 0, IDX_INTERN_C});
    auto intern = doctor_->getChildNode(internIdx);
    EXPECT_TRUE(internIdx.equal(intern->getNodeIdx()));
}

TEST_F(NodeTest, GetChildNode_NonExistent) {
    addSupervisor();
    addDoctorToSupervisor();
    addInternCollectionToDoctor();

    auto internIdx = NodeIdx({NODEIDX_ROOT, 0, 0, IDX_INTERN_B});
    auto intern = doctor_->getChildNode(internIdx);
    EXPECT_TRUE(internIdx.equal(intern->getNodeIdx()));
}
