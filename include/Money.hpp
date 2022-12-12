#ifndef MONEY_HPP
# define MONEY_HPP

# include <iostream>
# include <string>
# include <stdio.h>
# include "Bank.hpp"
// # include "Dollar.hpp"
// # include "Franc.hpp"
// #include "Expression.hpp"

class Money
{
	public:
		Money();
		Money(int amount, std::string currency);
		int	const &getMoney();
		std::string const &getClassType();
		std::string const &getCurrency();
		bool equals(Money money);
		Money times(int multiplier);
		Money franc(int amount);
		Money dollar(int amount);
		std::string currency();
		Money plus(Money addend);
		Money reduce(Bank bank, std::string to);
		Money &		operator+( Money const & rhs );

	protected:
		int					_amount;
		std::string	_class_type;
		std::string _currency; // 통화
	
	private:
		
};

#endif /* *********************************************************** MONEY_H */