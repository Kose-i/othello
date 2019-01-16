#include "Computer.hpp"

#include <iostream>
#include <istream>
#include <utility>
#include <memory>

#include "Board.hpp"
#include "Point.hpp"

Computer::Computer(std::shared_ptr<class Board>& board, const Board_env& com_color) :board_state(board), my_stone_color(com_color){};
Computer::~Computer(){};

void Computer::init()
{
  init_enemy_color();
};

void Computer::init_enemy_color()
{
  if(my_stone_color == Board_env::black)enemy_stone_color = Board_env::white;
  else enemy_stone_color = Board_env::black;
};

Point Computer::define_spot()
{
  std::vector<Point> put_able = board_state->put_able_spot(my_stone_color);
  int size = put_able.size();
  if (size == 0) {
    return Point(-1,-1);
  }
  int best_put = 0;
  int cost_minimum = -1000;

  std::cout << "Computer class: deine_spot\n";

  for (int i = 0;i < size;++i)
  {
    Board cp_board(*board_state);

    cp_board.put_stone(put_able[i] ,my_stone_color);
    //cp_board.print_board();

    long cost = calc_cost(cp_board, my_stone_color, enemy_stone_color);
    if(cost < cost_minimum) {
      cost_minimum = cost;// costmap[put_able[i].second][put_able[i].first] - 10 * pos.size();
      best_put = i;
    }
  }
  return put_able[best_put];
}

