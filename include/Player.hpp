#ifndef OTHELLO_PLAYER_HPP
#define OTHELLO_PLAYER_HPP

#include <vector>
#include <utility>
#include <memory>

#include "Board.hpp"
#include "Point.hpp"
#include "Hand.hpp"

class Player: public Hand
{
  private:
    std::shared_ptr<Board> board_state;
    Board_env my_stone_color;
    Board_env enemy_stone_color;
  public:
    Player(std::shared_ptr<Board>&, const Board_env&);
    virtual ~Player();
    void init()override;
    void init_enemy_stone();
    virtual Point define_spot()override;
};
#endif
