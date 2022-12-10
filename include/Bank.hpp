#ifndef BANK_HPP
# define BANK_HPP
# include "Money.hpp"
// #include "Expression.hpp"
// #include "Sum.hpp"
# include "Pair.hpp"
# include "HashTable.hpp"

class Bank{
  public:
    // Money reduce(Sum source, std::string to){
    //   // Sum sum = Sum(source.getMoney(), source.getCurrency());
    //   // Sum sum = Sum()
    //   // std::cout << "sum : ====================" << sum._addend.getMoney() << "\n";
  
    //   return source.reduce(*this, to);
    // };

    // int rate(std::string from, std::string to)
    // {
    //   return (from == "CHF") && (to == "USD") ? 2 : 1;
    // };


    void addRate(std::string from, std::string to, int rate)
    {
      rates.putTable(Pair(from, to), rate);
    };

    int rate(std::string from, std::string to){
      int rate = rates.getTable(Pair(from, to));
      return rate;
    };


  private:
    Hashtable rates;
};


#endif