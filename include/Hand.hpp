#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include <vector>
#include <utility>
#include "Board.hpp"

using Point = std::pair<int,int>;
class Hand
{
  public:
    Hand(){};
    ~Hand(){};
    virtual void definestone();
  private:
};
#endif
