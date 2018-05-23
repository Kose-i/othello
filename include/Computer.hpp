#ifndef OTHELLO_COMPUTER_HPP
#define OTHELLO_COMPUTER_HPP

#include "Board.hpp"
//#include "Hand.hpp"
//#include "Hyoukakansuu.hpp"
#include <vector>

class Computer// :Hand// , Hyoukakansuu
{
  friend class Board;
  public:
    Computer(class Board& , const Board_env&);
    ~Computer();
    Board* val;
    void define_spot();
    Board_env computer_stone;
  private:
    std::vector<std::vector<int>> costmap{
          {100,-40,20, 5, 5,20,-40,100},
          {-40,-80,-1,-1,-1,-1,-80,-40},
          { 20, -1, 5, 1, 1, 5, -1, 20},
          {  5, -1, 1, 0, 0, 1, -1,  5},
          {  5, -1, 1, 0, 0, 1, -1,  5},
          { 20, -1, 5, 1, 1, 5, -1, 20},
          {-40,-80,-1,-1,-1,-1,-80,-40},
          {100,-40,20, 5, 5,20,-40,100},
        };
};
#endif
