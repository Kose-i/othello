#ifndef OTHELLO_COMPUTER_HPP
#define OTHELLO_COMPUTER_HPP

#include "Board.hpp"
#include "Hand.hpp"
//#include "Hyoukakansuu.hpp"
#include <vector>

class Computer: public Hand// , Hyoukakansuu
{
  private:
    Board board_state;
    Board_env my_stone_color;
    Board_env enemy_stone_color;

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

  private://function
    void init_enemy_color();
  public:
    Computer(class Board&, const Board_env&);
    ~Computer();
    void init();
    Point define_spot();
};
#endif
