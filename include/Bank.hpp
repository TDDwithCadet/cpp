#ifndef BANK_HPP
# define BANK_HPP
#include "Money.hpp"
#include "Expression.hpp"
#include "Sum.hpp"

class Bank{
  public:
    Money reduce(Sum source, std::string to){
      // Sum sum = Sum(source.getMoney(), source.getCurrency());
      // Sum sum = Sum()
      // std::cout << "sum : ====================" << sum._addend.getMoney() << "\n";
  
      return source.reduce(to);
    }
};


#endif