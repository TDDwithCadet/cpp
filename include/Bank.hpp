#ifndef BANK_HPP
# define BANK_HPP
#include "Money.hpp"
#include "Expression.hpp"

class Bank{
  public:
    Money reduce(Money source, std::string to){
      return Money().dollar(10);
    }
};


#endif