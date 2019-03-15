#ifndef OTHELLO_COMPUTER_HPP
#define OTHELLO_COMPUTER_HPP

#include "Board.hpp"
#include "Hand.hpp"
#include "CalcCost.hpp"

#include <vector>
#include <memory>

class Computer: public Hand
{
  private:
    std::shared_ptr<Board> board_state;
    Board_env my_stone_color;
    Board_env enemy_stone_color;
    Agent_Computer calc_;

  private://function
    void init_enemy_color();
  public:
    Computer(std::shared_ptr<Board>&, const Board_env&);
    virtual ~Computer();
    void init()override;
    virtual Point define_spot()override;
};
#endif
