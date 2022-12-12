#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"
#include "Franc.hpp"
#include "Money.hpp"
#include "Sum.hpp"
// #include "Expression.hpp"
#include "Bank.hpp"

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

// TEST(TDD, testDiffentClassEquality) { 
//   EXPECT_EQ(Money(10, "CHF").currency(), Franc(10, "CHF").currency()); 
// }(p112 삭제)

TEST(TDD, testSimpleAddition){
  Money five = Money(5, "USD");
  Money add = five.plus(five);
  // Expression result = Expression(add.getMoney(), add.getCurrency());
  // Sum sum = Sum(five, five);
  Money money = Money(10, "USD");
  Bank bank = Bank();
  Money reduced = money.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(10).getMoney(), reduced.getMoney());
}

TEST(TDD, testPlusReturnSum){
  Money five = Money(5, "USD");
  Money add = five.plus(five);
  // Expression result = Expression(add.getMoney(), add.getCurrency());
  Sum sum = Sum(five, add);
  EXPECT_EQ(five.getMoney(), sum._augend.getMoney());
  EXPECT_EQ(add.getMoney(), sum._addend.getMoney());
}

TEST(TDD, testReduceSum){
  Sum sum = Sum(Money().dollar(3), Money().dollar(4));
  Bank bank = Bank();
  Money money = sum.reduce(bank, "USD");
  Money result = money.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(7).getMoney(), result.getMoney());
}

TEST(TDD, testReduceMoney){
  Bank bank = Bank();
  Money money = Money(1, "USD");
  std::cout << money.getMoney() << "\n";
  Money result = money.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(1).getMoney(), result.getMoney());
}

TEST(TDD, testReduceMoneyDifferentCurrency){
  Bank bank = Bank();
  bank.addRate("CHF", "USD", 2);
  Money money = Sum(Money(2, "CHF"), Money(0, "CHF")).reduce(bank, "CHF");
  Money result = money.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(1).getMoney(), result.getMoney());
}

// TEST(TDD, testArrayEquals){
//   EXPECT_EQ()
// }

TEST(TDD, testMixedAddition){
  Money fiveBucks = Money().dollar(5);
  Money tenFrancs = Money().franc(10);
  Bank bank = Bank();
  bank.addRate("CHF", "USD", 2);
  Sum sum = Sum(fiveBucks, tenFrancs);
  Money result = sum.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(10).getMoney(), result.getMoney());
}

TEST(TDD, testSumPlusMoney){
  Money fiveBucks = Money().dollar(5);
  Money tenFrancs = Money().franc(10);
  Bank bank = Bank();
  bank.addRate("CHF", "USD", 2);
  Sum sum = Sum(fiveBucks, tenFrancs).plus(fiveBucks);
  Money result = sum.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(15).getMoney(), result.getMoney());
}

TEST(TDD, testSumTimes){
  Money fiveBucks = Money().dollar(5);
  Money tenFrancs = Money().franc(10);
  Bank bank = Bank();
  bank.addRate("CHF", "USD", 2);
  Sum sum = Sum(fiveBucks, tenFrancs).times(2);
  Money result = sum.reduce(bank, "USD");
  EXPECT_EQ(Money().dollar(20).getMoney(), result.getMoney());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}