#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"

//test_case_name, test_name
TEST(TDD, testMultiplication) {
  Dollar five = Dollar(5);
  Dollar product = five.times(2);
  EXPECT_EQ(10, product._amount);
  product = five.times(3);
  EXPECT_EQ(15, product._amount);
}

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5).equals(Dollar(5)));
  EXPECT_TRUE(Dollar(5).equals(Dollar(6)));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}