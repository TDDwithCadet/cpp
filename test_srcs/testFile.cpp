#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"
#include "Money.hpp"
#include "Expression.hpp"
#include "Bank.hpp"
#include "Sum.hpp"

// test_case_name, test_name
TEST(TDD, testMultiplication) {
  Money five = Dollar(5, "USD");
  EXPECT_EQ(Dollar(10, "USD").getMoney(), five.times(2).getMoney());
  EXPECT_EQ(Dollar(15, "USD").getMoney(), five.times(3).getMoney());
}

// testFrancMultiplication(p112 삭제)

TEST(TDD, testEquality) {
  EXPECT_TRUE(Dollar(5, "USD").equals(Dollar(5, "USD")));
  EXPECT_FALSE(Dollar(5, "USD").equals(Dollar(6, "USD")));
  // EXPECT_TRUE(Franc(5, "CHF").equals(Franc(5, "CHF")));  Dollar/Franc 중복(p111 삭제, testEquality에서 중복된 영역 삭제함)
  // EXPECT_FALSE(Franc(5, "CHF").equals(Franc(6, "CHF")));
  EXPECT_FALSE(Franc(5, "CHF").equals(Money(Dollar(5, "USD"))));
}

TEST(TDD, testCurrency) { //p94, 통화개념을 표시하기 위하여 currency 도입
  EXPECT_EQ("USD", Dollar(1, "USD").currency());
  EXPECT_EQ("CHF", Franc(1, "CHF").currency());  
}

// TEST(TDD, testSimpleAddition){
//   Money sum = Money().dollar(5).plus(Money().dollar(5));
//   EXPECT_EQ(Money().dollar(10).getMoney(), sum.getMoney());
// }

TEST(TDD, testSimpleAddition){
  // Money *five = new Money(5, "USD");
  // Expression *result = &(*five).plus(*five);
  // Money result = (five).plus(five);
  // Bank bank = Bank();
  // Money reduced = bank.reduce(sum, "USD");
  Money five = Money(5, "USD");
  Money add = five.plus(five);
  Expression result = Expression(add.getMoney(), add.getCurrency());
  Sum sum = Sum(result.getMoney());
  EXPECT_EQ(five.getMoney(), sum.augend.getMoney());
  EXPECT_EQ(five.getMoney(), sum.addend.getMoney());
}

// TEST(TDD, testDiffentClassEquality) { 
//   EXPECT_EQ(Money(10, "CHF").currency(), Franc(10, "CHF").currency()); 
// }(p112 삭제)


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}