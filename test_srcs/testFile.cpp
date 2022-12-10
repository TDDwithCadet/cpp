#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"
#include "Money.hpp"

//test_case_name, test_name
TEST(TDD, testMultiplication) {
  Money five = Dollar(5, "USD");
  EXPECT_EQ(Dollar(10, "USD").getMoney(), five.times(2).getMoney());
  EXPECT_EQ(Dollar(15, "USD").getMoney(), five.times(3).getMoney());
}

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5, "USD").equals(Dollar(5, "USD")));
  EXPECT_FALSE(Dollar(5, "USD").equals(Dollar(6, "USD")));
  // EXPECT_TRUE(Franc(5, "CHF").equals(Franc(5, "CHF"))); 
  // EXPECT_FALSE(Franc(5, "CHF").equals(Franc(6, "CHF")));
  EXPECT_FALSE(Franc(5, "CHF").equals(Money(Dollar(5, "USD"))));
}

TEST(TDD, testCurrency) { //p94, 통화개념을 표시하기 위하여 currency 도입
  EXPECT_EQ("USD", Dollar(1, "USD").currency());
  EXPECT_EQ("CHF", Franc(1, "CHF").currency());  
}

TEST(TDD, testDiffentClassEquality) { 
  EXPECT_EQ(Money(10, "CHF").currency(), Franc(10, "CHF").currency()); 
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}