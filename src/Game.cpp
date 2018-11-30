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
  /**/
  player_name[Board_env::black] = "computer";
  player_name[Board_env::white] = "player1";
  /**/
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
  Point pos;
  for (int i {};i < 2;++i) {

    pos = players[Board_env::black]->define_spot();
  board->put_stone(pos,Board_env::black);
  board->print_board();
    pos = players[Board_env::white]->define_spot();
    board->put_stone(pos,Board_env::white);
  board->print_board();
  }
};

void Game::result()
{
  Board_env winner_stone = board->define_winner();

  if (winner_stone == Board_env::blank) {
    std::cout << "draw\n";
  } else if (winner_stone == Board_env::black) {

    std::cout << "winner is black\n";
    std::cout << player_name[Board_env::black] << '\n';

  } else if (winner_stone == Board_env::white) {

    std::cout << "winner is white\n";
    std::cout << player_name[Board_env::white] << '\n';

  } else {
    throw("no winner no draw");
  }
}
