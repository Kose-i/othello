#include "Hyoukakansuu.hpp"

#include <vector>

#include "Board.hpp"
#include "Point.hpp"

long Hyoukakansuu::calc_cost(const Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
{
  std::vector<Point> pos = cp_board.put_able_spot(enemy_stone);

  long cost_from_put_able_spot = pos.size();
  long cost_from_costmap {};

  for (auto i = 0;i < 8;++i) {
    for (auto j = 0;j < 8;++j) {
      if (cp_board(Point(i,j)) == my_stone) {
        cost_from_costmap += costmap[i][j];
      } else if (cp_board(Point(i,j) ) == enemy_stone) {
        cost_from_costmap -= costmap[i][j];
      }
    }
  }
  return cost_from_costmap - 5 * cost_from_put_able_spot;
};
