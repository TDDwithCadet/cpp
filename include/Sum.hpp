#ifndef SUM_HPP
# define SUM_HPP
# include "Money.hpp"
# include "Expression.hpp"
  
  class Sum : public Expression{
    public:
      Sum(int amount){
        _amount = amount;
      };

      Sum(Money augend, Money addend)
      {

      };
      Money augend;
      Money addend;
  };

#endif