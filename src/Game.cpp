#include "Game.hpp"
#include "Point.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Computer.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <memory>

Game::Game():board{std::make_shared<Board>()} ,ifs{file_path}
{
  if (!ifs.is_open()) {
    std::cout << "cant open:" << file_path << '\n';
    throw("cant open %s", file_path);
  }
  std::string s1, s2;
  std::getline(ifs, s1);
  std::getline(ifs, s2);
  if (s1.find("Black") && s2.find("White")) {
  } else if (s1.find("White") && s2.find("Black")) {
  }
};

Game::~Game()
{
  ifs.close();
};

void Game::init()
{
//  class Computer* comp(board, Board_env::black);
//  class Player* player(board, Board_env::white);

  players[Board_env::black] = dynamic_cast<Hand*>(new Computer(board,Board_env::black));
  players[Board_env::white] = dynamic_cast<Hand*>(new Player(board, Board_env::white));
};

void Game::run()
{
  board->print_board();
  Point pos = players[Board_env::black]->define_spot();
  std::cout << "x :" << pos.get_x() << "y :" << pos.get_y() << '\n';
  //board->put_stone(pos,Board_env::black);
};
