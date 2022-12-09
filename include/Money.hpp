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

	protected:
		int	_amount;
	private:
		
};

#endif /* *********************************************************** MONEY_H */