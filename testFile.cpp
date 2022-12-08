#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"

//test_case_name, test_name
TEST(TDD, testMultiplication) {
  Dollar five = Dollar(5);
  EXPECT_EQ(Dollar(10)._amount, five.times(2)._amount);
  EXPECT_EQ(Dollar(15)._amount, five.times(3)._amount);
}

TEST(TDD, testMultiplication2) {
  Franc five = Franc(5);
  EXPECT_EQ(Franc(10)._amount, five.times(2)._amount);
  EXPECT_EQ(Franc(15)._amount, five.times(3)._amount);
}

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
  EXPECT_FALSE(Dollar(5).equals(Dollar(6)));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}