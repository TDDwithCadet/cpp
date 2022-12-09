#ifndef MONEY_HPP
# define MONEY_HPP

# include <iostream>
# include <string>
# include <stdio.h>
# include "Dollar.hpp"

class Money
{

	public:
		Money(){

		};

		Money(int amount)
		{
			_amount = amount;
		};

		int	const &getMoney()
		{
			return _amount;
		};

		std::string const &getClassType()
		{
			return _class_type;
		};

		bool equals(Money money){
			Money _money = money; 
			// std::cout << "class_type : " <<_class_type << "\n";
			return _amount == _money.getMoney() && _class_type == money.getClassType(); // 공용으로 바꿈, 
		};

		int times(int multiplier)
		{
			return _amount * multiplier;
		}			


		

	protected:
		int					_amount;
		std::string	_class_type;
	
	private:
		
};

// Dollar dollar(int amount) // 이 형식은 되지 않는 것 같다.(p89)
// {
// 	return (Dollar(amount));
// }




#endif /* *********************************************************** MONEY_H */