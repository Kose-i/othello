#ifndef CalcCost_hpp
#define CalcCost_hpp
class Agent_Computer{
  public:
    static int reward_win;
    static int reward_lose;
  private:
  public:
    Agent_Computer();
    long CalcCost()const;
};
#endif
