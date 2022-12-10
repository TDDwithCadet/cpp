#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

class Pair{
  private:
    std::string _from;
    std::string _to;
  
  public:
    Pair(std::string from, std::string to)
    {
      _from = from;
      _to = to;
    }

    std::string getTo()
    {
      return _to;
    }

    std::string getFrom()
    {
      return _from;
    }

    bool equals(Pair pair)
    {
      return _from == pair.getFrom() && _to == pair.getTo();
    }

    int hashCode()
    {
      return 0;
    }


};
#endif