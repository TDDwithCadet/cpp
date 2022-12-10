#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP
#include "Money.hpp"

// class Money;
class Expression : public Money
{
  public :
    Expression(){};
    Expression(int amount, std::string currency) 
    {
      _amount = amount;
      _currency = currency;
    };
};

#endif