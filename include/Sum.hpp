#ifndef SUM_HPP
# define SUM_HPP
# include "Money.hpp"
// # include "Expression.hpp"
// # include <iostream>
  class Sum : public Money{
    public:
      Money _augend;
      Money _addend;
      
      Sum(int amount){
        _amount = amount;
      };

      Sum(int amount, std::string currency){
        _amount = amount;
        _currency = currency;
      };

      Sum(Money augend, Money addend)
      {
        _augend = augend;
        _addend = addend;
      };

      Sum(Sum origin, Money addend)
      {
        Bank bank = Bank();
        _augend = origin.reduce(bank, "USD");
        std::cout << "============augned test : " << _augend.getMoney() << "\n";
        _addend = addend;
      };

      Money reduce(Bank bank, std::string to){
        int amount = _augend.reduce(bank, to).getMoney() + _addend.reduce(bank, to).getMoney();
        return Money(amount, to);
      };

      Sum plus(Money addend){
        return Sum(*this, addend);
      };

      Sum times(int multiplier){
        return Sum(_augend.times(multiplier), _addend.times(multiplier));
      };

      Money getAugend()
      {
        return _augend;
      };

      Money getAddend()
      {
        return _addend;
      };
  };

#endif