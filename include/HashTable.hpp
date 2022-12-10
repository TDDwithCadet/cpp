#ifndef HASHTABLE_HPP
# define HASHTABLE_HPP

# include <iostream>
# include <map>
# include <iostream>
# include "Pair.hpp"

class Hashtable{
  private:
    std::map<std::string, int> _table;
  
  public:
    Hashtable(){
      _table.insert(std::pair<std::string, int>("CHFUSD", 2));
      std::cout << "check : " <<_table["CHFUSD"] <<"\n";
    };

    void putTable(Pair pair, int rate){
      std::string sum_string = pair.getFrom() + pair.getTo();
      _table.insert(std::pair<std::string, int>(sum_string, rate));
    }

    int getTable(Pair pair)
    {
      std::cout << pair.getFrom() + pair.getTo() << "\n";
      if (_table[pair.getFrom() + pair.getTo()] == 0)
        return 1;
      return _table[pair.getFrom() + pair.getTo()];
    };



};
#endif