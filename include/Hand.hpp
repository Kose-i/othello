#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include <vector>
#include <utility>
#include "Board.hpp"

using Point = std::pair<int,int>;
class Hand
{
  public:
    virtual Hand(class Board, const Board_env&){};
    virtual ~Hand(){};
    virtual void definestone();
  private:
    Board_env my_board_env;
};
#endif
