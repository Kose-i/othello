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

Costmap1::Costmap1()
{
  init_param("../config/param_for_costmap/test.cpp");
}
Costmap1::Costmap1(const std::string& filename)
{
  init_param(filename);
}
void Costmap1::init_param(const std::string& filename)
{
  std::ifstream ifs;
  ifs.open(filename);
  if (ifs.is_open()) {
    throw("cant open %s",filename);
  }

  ifs >> param1 >> param2 >> param3 >> param4 >> param5 >> param6 >> param7 >> param8 >> param9;
  ifs.close();
}
long Costmap1::calc_cost(const Board& cp_board, const Board_env& my_stone, const Board_env& enemy_stone)
{
  long cost_from_costmap {};
  Point pos;
  for (auto i = 0;i < 8;++i) {
    pos.set_y(i);
    for (auto j = 0;j < 8;++j) {
      pos.set_x(j);

      if (cp_board.get_board_env(pos) == my_stone) {
        cost_from_costmap += calc_costmap(pos);
      } else if (cp_board.get_board_env(pos) == enemy_stone) {
        cost_from_costmap -= calc_costmap(pos);
      }
    }
  }
  return cost_from_costmap;
};

long Costmap1::calc_costmap(const Point& pos)
{
  for (auto x : pos_1) {
    if (x == pos) return param1;
  }
  for (auto x : pos_2) {
    if (x == pos) return param2;
  }
  for (auto x : pos_3) {
    if (x == pos) return param3;
  }
  for (auto x : pos_4) {
    if (x == pos) return param4;
  }
  for (auto x : pos_5) {
    if (x == pos) return param5;
  }
  for (auto x : pos_6) {
    if (x == pos) return param6;
  }
  for (auto x : pos_7) {
    if (x == pos) return param7;
  }
  for (auto x : pos_8) {
    if (x == pos) return param8;
  }
  for (auto x : pos_9) {
    if (x == pos) return param9;
  }
};
