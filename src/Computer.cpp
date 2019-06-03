#include "Computer.hpp"

#include <iostream>
#include <istream>
#include <utility>
#include <memory>

#include "Board.hpp"
#include "Point.hpp"
#include "CalcCost.hpp"

Computer::Computer(std::shared_ptr<class Board>& board, const Board_env& com_color) :board_state(board), my_stone_color(com_color), calc_(Agent_Computer(board, com_color)){};
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
  auto size = put_able.size();
  if (size == 0) {
    return Point(-1,-1);
  }

  std::cout << "Computer class: define_spot\n";

  return calc_.select_high_Qparam(); //TEST
}

