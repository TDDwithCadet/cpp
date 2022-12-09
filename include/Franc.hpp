#ifndef FRANC_HPP
# define FRANC_HPP
#include "Money.hpp"

class Franc : public Money
{
	public:

		Franc(int amount, std::string currency){
			_amount = amount;
			_class_type = typeid(this).name();
			_currency = currency;
		};

		// Money times(int multiplier){ //dollor, franc >> money로 통일(p88)
		// 	return Franc(_amount * multiplier); // 5CHF X 2 = 10CHF
		// };

	private:
};

#endif