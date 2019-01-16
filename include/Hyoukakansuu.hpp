#ifndef OTHELLO_HYOUKAKANSUUHPP
#define OTHELLO_HYOUKAKANSUUHPP

#include <vector>

#include "Point.hpp"
#include "Board.hpp"

class Hyoukakansuu
{
  private:
    std::vector<Point> edge{{0,0},{0,7},{7,0},{7,7}};
    std::vector<Point> edge_surround{{1,0},{1,1},{0,1},
    {0,6},{1,6},{1,7},
    {6,0},{6,1},{7,1},
    {7,6},{6,6},{6,7}};

    std::vector<std::vector<int>> costmap{
          {100,-40,20, 5, 5,20,-40,100},
          {-40,-80,-1,-1,-1,-1,-80,-40},
          { 20, -1, 5, 1, 1, 5, -1, 20},
          {  5, -1, 1, 0, 0, 1, -1,  5},
          {  5, -1, 1, 0, 0, 1, -1,  5},
          { 20, -1, 5, 1, 1, 5, -1, 20},
          {-40,-80,-1,-1,-1,-1,-80,-40},
          {100,-40,20, 5, 5,20,-40,100},
        };
  public:
    long calc_cost(const Board&, const Board_env&, const Board_env&);
    long calc_costmap(const Board&, const Board_env&, const Board_env&);
};
#endif
