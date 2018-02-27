#include "Computer.hpp"

#include <iostream>
#include <istream>
#include <utility>

#include "Board.hpp"

std::istream& operator>>(std::istream& is , Point& pos)
{
  std::cin >> pos.first >> pos.second;
  return is;
}

Computer::Computer(class Board& board) :val(&board), computer_stone(Board_env::black){};
Computer::~Computer(){};

void Computer::define_spot()
{
  std::vector<Point> put_able = val->put_able_spot(computer_stone);
  int best_put = 0;
  int count_enemy = 60;
  for (const auto& e : put_able)
  {
    Board cp_board;
    cp_board.board = val->board;
    cp_board.put_stone(e,computer_stone);
    if(cp_board.put_able(define_enemy_color(computer_stone).size() < )
  }
  val->put_stone(pos,computer_stone);
}
