#ifndef OTHELLO_PLAYER_HPP
#define OTHELLO_PLAYER_HPP

#include <iostream>
#include <vector>
#include <utility>
#include "Board.hpp"
//#include "Hand.hpp"

class Player// : Hand
{
  friend class Board;
  public:
    Player(class Board&, const Board_env&);
    ~Player();
    Board* val;
    void define_spot();
    Board_env player_stone;
};
#endif
