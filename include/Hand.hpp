#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include "Board.hpp"
#include "Point.hpp"

#include <vector>

class Hand
{
  public:
    Hand(class Board board_val_, const Board_env& board_env) :board_val(board_val_), my_board_env(board_env)
    {};
    virtual ~Hand(){};
    virtual Point define_spot();
  private:
    Board_env my_board_env;
    Board board_val;
};
#endif
