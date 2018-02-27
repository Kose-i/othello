#ifndef OTHELLO_COMPUTER_HPP
#define OTHELLO_COMPUTER_HPP

#include "Board.hpp"
#include "Hand.hpp"
//#include "Hyoukakansuu.hpp"

class Computer //:Hand , Hyoukakansuu
{
  friend class Board;
  public:
    Computer(class Board&);
    ~Computer();
    Board* val;
    void define_spot();
    Board_env computer_stone;
};
#endif
