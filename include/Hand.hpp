#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include "Board.hpp"
#include "Point.hpp"

#include <vector>

class Hand
{
  public:
    Hand();
    virtual ~Hand();

    virtual void init()=0;

    virtual Point define_spot()=0;
};
#endif
