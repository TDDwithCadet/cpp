#ifndef FRANC_HPP
# define FRANC_HPP
#include "Money.hpp"

class Franc : public Money
{
	public:

		Franc(int amount){
			_amount = amount;
		};

		Franc times(int multiplier){
			return Franc(_amount * multiplier); // 5CHF X 2 = 10CHF
		};

		bool equals(Franc franc){
			Money money = (Money) franc; 
			return _amount == money.getMoney(); // equals()
		};

	private:
};

#endif