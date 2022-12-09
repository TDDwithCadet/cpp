#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"
#include "Money.hpp"

//test_case_name, test_name
TEST(TDD, testMultiplication) {
  Dollar five = Dollar(5);
  EXPECT_EQ(Dollar(10).getMoney(), five.times(2).getMoney());
  EXPECT_EQ(Dollar(15).getMoney(), five.times(3).getMoney());
}

TEST(TDD, testMultiplication2) {
  Franc five = Franc(5);
  EXPECT_EQ(Franc(10).getMoney(), five.times(2).getMoney());
  EXPECT_EQ(Franc(15).getMoney(), five.times(3).getMoney());
}

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
  EXPECT_FALSE(Dollar(5).equals(Dollar(6)));
  // EXPECT_TRUE(Franc(5).equals(Franc(5))); //공용 equals
  // EXPECT_FALSE(Franc(5).equals(Franc(6))); //공용 equals
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}