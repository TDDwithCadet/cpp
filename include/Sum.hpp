#ifndef SUM_HPP
# define SUM_HPP
# include "Money.hpp"
// # include "Expression.hpp"
  
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

      Money reduce(Bank bank, std::string to){
        int amount = _augend.getMoney() + _addend.getMoney();
        return Money(amount, to);
      };
  };

#endif