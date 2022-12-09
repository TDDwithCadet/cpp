#ifndef DOLLAR_HPP
# define DOLLAR_HPP
#include "Money.hpp"


class Dollar : public Money
{
	public:

		Dollar(int amount)
		{
			_amount = amount;
			_class_type = typeid(this).name();
		};

		Dollar times(int multiplier){
			// _amount = _amount * multiplier; // $5 X 2 = $10 
			return Dollar(_amount * multiplier); // Dollar 부작용?
		};

	private:
};

#endif