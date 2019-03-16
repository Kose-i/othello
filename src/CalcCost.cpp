#include "CalcCost.hpp"

#include <memory>

int Agent_Computer::reward_win = 1;
int Agent_Computer::reward_draw = 0;
int Agent_Computer::reward_lose = -1;

Agent_Computer::Agent_Computer(){};
long Agent_Computer::CalcCost(const Point& pos)const{return 1;};

Point Agent_Computer::select_random_action(){};

Point Agent_Computer::select_high_Qparam()const{
  Point good_pos{};
  long high_cost {};
  for (const Point& tmp_pos : board_state->put_able_spot(my_stone)) {
    if (high_cost < CalcCost(tmp_pos)) {
      high_cost = CalcCost(tmp_pos);
      good_pos = tmp_pos;
    }
  }
  return good_pos;
};

Point Agent_Computer::select_action()const
{
};
