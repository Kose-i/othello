#include "Costmap1.hpp"

#include <vector>
#include <string>
#include <fstream>

#include "Board.hpp"
#include "Point.hpp"

/*
    Param_type param1;
    Param_type param2;
    Param_type param3;
    Param_type param4;
    Param_type param5;
    Param_type param6;
    Param_type param7;
    Param_type param8;
    Param_type param9;

    *{1,2,4,5
    *{2,3,6,7
    *{4,6,8,9
    *{5,7,9
*/

Costmpap1::Costmap1(const std::string& filename)
{
  std::ifstream ifs(filename);
};
long Costmap1::calc_cost(const Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
{
};

long Costmap1::calc_costmap(const Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
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
