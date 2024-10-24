#include <sway/core/misc/atomicidgenmanager.hpp>
#include <sway/defines.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

#include <functional>

NS_SHORT_SWAY()
NS_SHORT(core);

class Obj {
public:
};

TEST(IdGen, temp) {
  misc::IdGen gen;
  EXPECT_EQ(gen.next(), 1);
  EXPECT_EQ(gen.next(), 2);
  EXPECT_EQ(gen.next(), 3);
}

TEST(AtomicIdGenManager, next) {
  misc::AtomicIdGenManager<Obj> gen;
  auto id_1 = gen.next();
  gen.increment(id_1);
  std::cout << "id_1 " << id_1 << std::endl;

  auto id_2 = gen.next();
  gen.increment(id_2);
  std::cout << "id_2 " << id_2 << std::endl;

  auto id_3 = gen.next();
  gen.increment(id_3);
  std::cout << "id_3 " << id_3 << std::endl;

  gen.free(id_2, [](bool rejected) { std::cout << std::boolalpha << "free: " << rejected << std::endl; });

  auto id_4 = gen.next();
  gen.increment(id_4);
  std::cout << "id_4 " << id_4 << std::endl;
  EXPECT_EQ(id_4, id_2);

  auto id_5 = gen.next();
  gen.increment(id_5);
  std::cout << "id_5 " << id_5 << std::endl;
}

TEST(AtomicIdGenManager, add) {
  misc::AtomicIdGenManager<Obj> gen;
  auto obj_1 = gen.add("obj_1", std::make_unique<Obj>());
  std::cout << "obj_1 " << obj_1 << std::endl;

  auto obj_2 = gen.add("obj_2", std::make_unique<Obj>());
  std::cout << "obj_2 " << obj_2 << std::endl;

  auto obj_3_1 = gen.add("obj_3", std::make_unique<Obj>());
  std::cout << "obj_3_1 " << obj_3_1 << std::endl;
  auto obj_3_2 = gen.add("obj_3", std::make_unique<Obj>());
  std::cout << "obj_3_2 " << obj_3_2 << std::endl;

  gen.remove(obj_1);
  gen.remove(obj_2);
  std::cout << "obj_4 " << gen.add("obj_4", std::make_unique<Obj>()) << std::endl;
}
