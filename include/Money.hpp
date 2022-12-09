#ifndef MONEY_HPP
# define MONEY_HPP

# include <iostream>
# include <string>

class Money
{

	public:
		Money(){

		};
		int	const &getMoney()
		{
			return _amount;
		};
		
		bool equals(Money money){
			Money _money = money; 
			return _amount == _money.getMoney(); // 공용으로 바꿈, 
		};

	protected:
		int	_amount;
	private:
		
};

#endif /* *********************************************************** MONEY_H */