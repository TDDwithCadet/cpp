#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
// #include "multi.h"

// TEST(test_case_name, test_name) {
//   EXPECT_EQ(1, multi(1,1));
//   //EXPECT_EQ는 result가 1*1는 1이기때문에 1을 넣어줘야함.
// }

TEST(test_case_name, test_name) {
  Dollar five = Dollar(5);
	five.times(2);
  EXPECT_EQ(10, five._amount);
  //EXPECT_EQ는 result가 1*1는 1이기때문에 1을 넣어줘야함.
}

// void testMultiplication()
// {
// 	Dollar five = new Dollar(5);
// 	five.times(2);
// 	ASSERT_EQ(10, five.amount);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}