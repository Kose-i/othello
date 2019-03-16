#ifndef CalcCost_hpp
#define CalcCost_hpp
/*
Q-network
*/

#include <string>
#include <memory>

#include "Point.hpp"
#include "Board.hpp"

class Agent_Computer{
  public:
    static int reward_win;
    static int reward_draw;
    static int reward_lose;
  private:
    std::string file_name;
    std::shared_ptr<Board> board_state;
    Board_env my_stone;

  private:
    Point select_random_action();
    long CalcCost(const Point&)const;
  public:
    Agent_Computer();
    Point select_high_Qparam()const;//内部でCalcCost()を使用
    Point select_action()const;
};
#endif
