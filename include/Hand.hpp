#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include "Board.hpp"
#include "Point.hpp"

#include <vector>

class Hand
{
  public:
    Hand();
    virtual Point define_spot();
    virtual ~Hand();
};
#endif
