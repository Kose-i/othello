#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include "Board.hpp"
#include "Point.hpp"

#include <vector>

class Hand
{
  private:
    Board board_state;
    Board_env my_stone_color;
    Board_env enemy_stone_color;
  public:
    Hand(class Board&, const Board_env&);
    Point define_spot();
    virtual ~Hand();
};
#endif
