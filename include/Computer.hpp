#ifndef OTHELLO_COMPUTER_HPP
#define OTHELLO_COMPUTER_HPP

#include "Board.hpp"
#include "Hand.hpp"
#include "Hyoukakansuu.hpp"
#include <vector>
#include <memory>

class Computer: public Hand ,private Hyoukakansuu
{
  private:
    std::shared_ptr<Board> board_state;
    Board_env my_stone_color;
    Board_env enemy_stone_color;

  private://function
    void init_enemy_color();
  public:
    Computer(std::shared_ptr<Board>&, const Board_env&);
    ~Computer();
    void init();
    Point define_spot();
};
#endif
