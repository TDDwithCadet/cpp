#include "Money.hpp"

Money::Money(){

};

Money::Money(int amount, std::string currency)
{
  _amount = amount;
  _currency = currency;
};

int	const &Money::getMoney()
{
  return _amount;
};

std::string const &Money::getClassType()
{
  return _class_type;
};

std::string const &Money::getCurrency()
{
  return _currency;
};

bool Money::equals(Money money){
  Money _money = money; 
  // std::cout << "class_type : " <<_class_type << "\n";
  return _amount == _money.getMoney() && _currency == money.getCurrency(); // 공용으로 바꿈, 
};

Money Money::times(int multiplier)
{
  return Money(_amount * multiplier, _currency);
};

Money Money::franc(int amount)
{
  return Money(amount, "CHF");
}

Money Money::dollar(int amount)
{
  return Money(amount, "USD");
}

std::string Money::currency(){ 
  // p95, 이제 두 currency()가 동일하므로 변수 선언과 currency() 구현을 둘 다 위로 올릴(push up)수 있게 됐다.
  return _currency;
};

// Money plus(Money addend){ //p114 추가
// 	return Money(_amount + addend.getMoney(), _currency);
// };

Money Money::plus(Money addend){
    return (Money(_amount + addend.getMoney(), _currency));
}

Money Money::reduce(Bank bank, std::string to){
  int rate = bank.rate(_currency, to);
  std::cout << "rate??????" << rate << "\n";
  return Money(_amount / rate, to);
};