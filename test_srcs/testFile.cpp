#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"
#include "Money.hpp"

//test_case_name, test_name
TEST(TDD, testMultiplication) {
  Money five = Dollar(5);
  EXPECT_EQ(Dollar(10).getMoney(), Money(five.times(2)).getMoney());
  EXPECT_EQ(Dollar(15).getMoney(), Money(five.times(3)).getMoney());
}

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
  EXPECT_FALSE(Dollar(5).equals(Dollar(6)));
  EXPECT_TRUE(Franc(5).equals(Franc(5))); 
  EXPECT_FALSE(Franc(5).equals(Franc(6)));
  EXPECT_FALSE(Franc(5).equals(Money(Dollar(5))));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}