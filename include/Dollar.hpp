#ifndef DOLLAR_HPP
# define DOLLAR_HPP
#include "Money.hpp"

class Dollar : public Money
{
	public:

		Dollar(int amount, std::string currency)
		{
			_amount = amount;
			_class_type = typeid(this).name();
			_currency = currency;
		};

		// Money times(int multiplier){ //dollor, franc >> money로 통일(p88)
		// 	return Dollar(_amount * multiplier); // Dollar 부작용?
		// };

	private:
};

#endif