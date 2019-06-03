#include "CalcCost.hpp"

#include <memory>

#include <iostream> // DEBUG

int Agent_Computer::reward_win = 1;
int Agent_Computer::reward_draw = 0;
int Agent_Computer::reward_lose = -1;

Agent_Computer::Agent_Computer(std::shared_ptr<Board>& board, const Board_env& myStone): board_state(board), my_stone(myStone){};

/*
    std::string file_name;
    std::shared_ptr<Board> board_state;
    Board_env my_stone;
*/
long Agent_Computer::CalcCost(const Point& pos)const{return 1;};

Point Agent_Computer::select_random_action(){};

Point Agent_Computer::select_high_Qparam()const{
  Point good_pos{};
  long high_cost {};
  std::cout << "Agent_Computer select_high_QParam\n"; //DEBUG
  std::vector<Point> pos_Box = board_state->put_able_spot(my_stone);
  for (const Point& tmp_pos : pos_Box) {
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
