#ifndef OTHELLO_COSTMAP_1_HPP
#define OTHELLO_COSTMAP_1_HPP

#include <vector>
#include <string>

#include "Point.hpp"
#include "Board.hpp"

class Costmap1
{
  public:
    Costmap1();
    Costmap1(const std::string&);
    void init_param(const std::string&);
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
    Param_type param10;
    /*
    *{1,2,4,5
    *{2,3,6,7
    *{4,6,8,9
    *{5,7,9,10
    */
  private:
    std::vector<Point> pos_1{{0,0},{0,7},{7,0},{7,7}};
    std::vector<Point> pos_2{
      {0,1},{1,0},{0,6},{1,7},
      {7,1},{6,0},{7,6},{6,7}
    };
    std::vector<Point> pos_3{
      {1,1},{1,6},{6,1},{6,6}
    };
    std::vector<Point> pos_4{
      {0,2},{2,0},{0,5},{2,7},
      {5,0},{7,2},{5,7},{7,5}
    };
    std::vector<Point> pos_5{
      {0,3},{3,0},{0,4},{4,0},
      {7,3},{3,7},{7,4},{4,7}
    };
    std::vector<Point> pos_6{
      {1,2},{2,1},{1,5},{2,6},
      {5,1},{6,2},{5,6},{6,5}
    };
    std::vector<Point> pos_7{
      {1,3},{3,1},{1,4},{4,1},
      {6,3},{3,6},{6,4},{4,6}
    };
    std::vector<Point> pos_8{
      {2,2},{2,5},{5,2},{5,5}
    };
    std::vector<Point> pos_9{
      {3,2},{2,3},{4,2},{5,3},
      {3,5},{2,4},{4,5},{5,4}
    };
    std::vector<Point> pos_10{
      {4,4},{4,5},{5,4},{5,5}
    };

    long calc_costmap(const Point&);
  public:
    long calc_cost(const Board&, const Board_env&, const Board_env&);
};
#endif
