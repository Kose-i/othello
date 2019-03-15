#ifndef CalcCost_hpp
#define CalcCost_hpp
/*
Q-network
*/

#include <string>
#include "Point.hpp"

class Agent_Computer{
  public:
    static int reward_win;
    static int reward_draw;
    static int reward_lose;
  private:
    std::string file_name;

  private:
    Point select_random_action();
    Point select_high_Qparam();//内部でCalcCost()を使用
    void save_model();
  public:
    Agent_Computer();
    Point select_action()const;
    long CalcCost()const;
};
#endif
