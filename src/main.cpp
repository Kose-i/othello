#include <iostream>
#include <utility>
#include <vector>

#include "Board.hpp"
#include "Player.hpp"

using Point = std::pair<int,int>;
int main()
{
  Board board;
  board.print_board();
  std::vector<Point> pos = board.put_able_spot(Board_env::black);
  for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
  Player player(board);
  player.define_spot();
  board.print_board();
  pos = board.put_able_spot(Board_env::white);
  for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
}
