#include "Computer.hpp"

#include <iostream>
#include <istream>
#include <utility>

#include "Board.hpp"
#include "Point.hpp"

Computer::Computer(class Board& board, const Board_env& com_color) :board_state(board), my_stone_color(com_color){};
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
  int best_put = 0;
  int count_enemy = -1000;

  for (int i = 0;i < size;++i)
  {
    Board cp_board(board_state);

    cp_board.put_stone(put_able[i] ,my_stone_color);
    cp_board.print_board();

    std::vector<Point> pos = cp_board.put_able_spot(enemy_stone_color);
    for (auto& e : pos) {
      std::cout << "x is " << e.get_x() << "y is " << e.get_y() << '\n';
    }
    int cost = 0;
    if((cost = costmap[put_able[i].get_y()][put_able[i].get_x()] - 5 * pos.size()) > count_enemy)
    {
      count_enemy =cost;// costmap[put_able[i].second][put_able[i].first] - 10 * pos.size();
      std::cout <<"this cost is "<< cost << '\n';
      best_put = i;
    }
  }
  return put_able[best_put];
}

