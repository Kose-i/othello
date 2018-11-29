#ifndef OTHELLO_HYOUKAKANSUUHPP
#define OTHELLO_HYOUKAKANSUUHPP

#include <vector>
#include <utility>

using Point = std::pair<int,int>;
class Hyoukakansuu
{
  private:
    std::vector<Point> edge{{0,0},{0,7},{7,0},{7,7}};
    std::vector<Point> edge_surround{{1,0},{1,1},{0,1},
    {0,6},{1,6},{1,7},
    {6,0},{6,1},{7,1},
    {7,6},{6,6},{6,7}};
  public:
    calc_cost();
};
#endif
