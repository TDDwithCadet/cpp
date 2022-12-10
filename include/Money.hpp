#ifndef MONEY_HPP
# define MONEY_HPP

# include <iostream>
# include <string>
# include <stdio.h>
// # include "Dollar.hpp"
// # include "Franc.hpp"


class Money
{

	public:
		Money(){

		};

		Money(int amount, std::string currency)
		{
			_amount = amount;
			_currency = currency;
		};

		int	const &getMoney()
		{
			return _amount;
		};

		std::string const &getClassType()
		{
			return _class_type;
		};

		std::string const &getCurrency()
		{
			return _currency;
		};

		bool equals(Money money){
			Money _money = money; 
			// std::cout << "class_type : " <<_class_type << "\n";
			return _amount == _money.getMoney() && _currency == money.getCurrency(); // 공용으로 바꿈, 
		};

		Money times(int multiplier)
		{
			return Money(_amount * multiplier, _currency);
		};
		
		Money franc(int amount)
		{
			return Money(amount, "CHF");
		}

		Money dollar(int amount)
		{
			return Money(amount, "USD");
		}

		std::string currency(){ 
			// p95, 이제 두 currency()가 동일하므로 변수 선언과 currency() 구현을 둘 다 위로 올릴(push up)수 있게 됐다.
			return _currency;
		};


		

	protected:
		int					_amount;
		std::string	_class_type;
		std::string _currency; // 통화
	
	private:
		
};



// static Money franc(int amount) {
// 	return Franc(amount, "CHF");
// }

// static Money dollar(int amount) {
// 	return Dollar(amount, "USD");
// }







#endif /* *********************************************************** MONEY_H */