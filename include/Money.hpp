#ifndef MONEY_HPP
# define MONEY_HPP

# include <iostream>
# include <string>
# include <stdio.h>


class Money
{

	public:
		Money(){

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

	protected:
		int					_amount;
		std::string	_class_type;
	private:
		
};

#endif /* *********************************************************** MONEY_H */