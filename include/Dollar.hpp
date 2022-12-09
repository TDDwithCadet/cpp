#ifndef DOLLAR_HPP
# define DOLLAR_HPP
#include "Money.hpp"

class Dollar : public Money
{
	public:

		Dollar(int amount){
			_amount = amount;
		};

		Dollar times(int multiplier){
			// _amount = _amount * multiplier; // $5 X 2 = $10 
			return Dollar(_amount * multiplier); // Dollar 부작용?
		};

		bool equals(Dollar dollar){
			return _amount == dollar.getMoney(); // equals()
		};

	private:
};

#endif