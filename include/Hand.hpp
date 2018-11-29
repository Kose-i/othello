#ifndef OTHELLO_HAND_HPP
#define OTHELLO_HAND_HPP

#include "Board.hpp"

#include <vector>
#include <utility>

class Hand
{
  using Point = std::pair<int,int>;

  public:
    Hand(class Board, const Board_env& board_env) :my_board_env(board_env)
    {};
    virtual ~Hand(){};
    virtual Point define_stone();
  private:
    Board_env my_board_env;
};
#endif
