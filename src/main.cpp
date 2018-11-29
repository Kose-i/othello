#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Computer.hpp"

int main(int argc, char** argv)
{
  Game game_;
  game_.init();
  game_.run();
  std::cout << "end";
  return 0;
}
#if 0
using Point = std::pair<int,int>;
int main()
{
  Board board;

  std::ifstream ifs("../config/detect_hand.txt");
  Board_env player1, player2;

  if (!ifs.is_open()) {
    std::cout << "can't open file";
    return -1;
  } else {
    std::string s1, s2;
    ifs >> s1 >> s2;
    if (s1.find("Black")&& s2.find("White")) {
    } else if (s1.find("White") && s2.find("Black")) {
    } else {
    }
    std::cout << ss;
  }

  Player player(board,Board_env::black);
  Computer com(board,Board_env::white);

  bool path_find = true;
  for(;true;path_find = true){

    path_find = true;
    std::vector<Point> pos = board.put_able_spot(Board_env::black);
    if (pos.size() == 0) {
      std::cout << "you are path\n";
    } else {
      path_find = false;
      board.print_board();
      for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
      player.define_spot();
    }
    board.print_board();

    pos = board.put_able_spot(Board_env::white);
    if(pos.size() == 0)
    {
      std::cout << "you are path\n";
      if(path_find == true)break;
      else continue;
    } else {
      path_find = false;
      for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
      com.define_spot();
      std::cout << "result is \n";
    }
  }

  Board_env winner =  board.define_winner();
  if (winner == Board_env::black)std::cout << "winner is black\n";
  else if (winner == Board_env::white)std::cout << "winner is white\n";
  else std::cout << "draw\n";
}
#endif
