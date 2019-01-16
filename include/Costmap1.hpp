#ifndef OTHELLO_COSTMAP_1_HPP
#define OTHELLO_COSTMAP_1_HPP

#include <vector>
#include <string>

#include "Point.hpp"
#include "Board.hpp"

class Costmap_1
{
  public:
    Costmap_1(const std::string& filename);
  private:
    using Param_type = int;
    Param_type param1;
    Param_type param2;
    Param_type param3;
    Param_type param4;
    Param_type param5;
    Param_type param6;
    Param_type param7;
    Param_type param8;
    Param_type param9;
    /*
    *{1,2,4,5
    *{2,3,6,7
    *{4,6,8,9
    *{5,7,9
    */
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
    long calc_costmap(Board&, const Board_env&, const Board_env&);
  public:
    long calc_cost(Board&, const Board_env&, const Board_env&);
};
#endif
