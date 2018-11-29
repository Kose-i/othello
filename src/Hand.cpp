#include "Hand.hpp"

#include <vector>
#include <utility>

#include "Board.hpp"

using Point = std::pair<int,int>;
Point Hand::define_stone()
{
  std::cout << "undefined\n";
  return {0,0};
};
