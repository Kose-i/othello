#ifndef OTHELLO_HYOUKAKANSUUHPP
#define OTHELLO_HYOUKAKANSUUHPP

#include <vector>
#include <utility>

using Point = std::pair<int,int>;
class Hyoukakansuu
{
  public:
    std::vector<Point> edge{{,0},{0,7},{7,0},{7,7}};
};
#endif
