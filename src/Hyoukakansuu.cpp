#include "Hyoukakansuu.hpp"

#include <vector>

#include "Board.hpp"
#include "Point.hpp"

long Hyoukakansuu::calc_cost(Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
{
  std::vector<Point> pos_putable = cp_board.put_able_spot(enemy_stone);

  //small is better
  long cost_from_enemy_put_able_spot = pos_putable.size();

  pos_putable = cp_board.put_able_spot(my_stone);

  //big is better
  long cost_from_my_put_able_spot = pos_putable.size();

  //big is better
  long cost_from_costmap = calc_costmap(cp_board, my_stone, enemy_stone);

  //minimam is necessary
  return (10*cost_from_enemy_put_able_spot - 3*cost_from_my_put_able_spot - cost_from_costmap);
};

long Hyoukakansuu::calc_costmap(Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
{
  long cost_from_costmap {};
  Point pos;
  for (auto i = 0;i < 8;++i) {
    pos.set_y(i);
    for (auto j = 0;j < 8;++j) {
      pos.set_x(j);

      if (cp_board.get_board_env(pos) == my_stone) {
        cost_from_costmap += costmap[i][j];
      } else if (cp_board.get_board_env(pos) == enemy_stone) {
        cost_from_costmap -= costmap[i][j];
      }
    }
  }
  return cost_from_costmap;
};
