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

  if (s1.find("Black") != std::string::npos && s2.find("White") != std::string::npos) {
    auto first = s1.find("Black");
    player_name[Board_env::black] = s1.substr(first + 6);

    first = s2.find("White");
    player_name[Board_env::white] = s2.substr(first + 6);

  } else if (s1.find("White") != std::string::npos && s2.find("Black") != std::string::npos) {
    auto first = s2.find("Black");
    player_name[Board_env::black] = s2.substr(first + 6);

    first = s1.find("White");
    player_name[Board_env::white] = s1.substr(first + 6);

  } else {
    std::cout << "require tag\n" << "Black [name]\n" << "White [name]\n";
    throw("file contents error");
  }
};

Game::~Game()
{
  ifs.close();
};

void Game::init()
{

  if(player_name[Board_env::black].find("computer") != std::string::npos) {
    players[Board_env::black] = std::make_unique<Computer>(board,Board_env::black);
  } else {
    players[Board_env::black] = std::make_unique<Player>(board,Board_env::black);
  }
  if(player_name[Board_env::white].find("computer") != std::string::npos) {
    players[Board_env::white] =  std::make_unique<Computer>(board,Board_env::white);
  } else {
    players[Board_env::white] = std::make_unique<Player>(board, Board_env::white);
  }

  board->init();
  players[Board_env::black]->init();
  players[Board_env::white]->init();

};

void Game::run()
{
  board->print_board();
  Point pos;
  Point path_pos(-1,-1);
  bool path_find = false;
  for (;true;) {

  
    pos = players[Board_env::black]->define_spot();
    if (pos != path_pos) {
      board->put_stone(pos,Board_env::black);
      path_find = false;
    } else {
      if (path_find == true) break;
      else path_find = true;
    }
    board->print_board();
    pos = players[Board_env::white]->define_spot();
    if (pos != path_pos) {
      board->put_stone(pos,Board_env::white);
      path_find = false;
    } else {
      if (path_find == true) break;
      else path_find = true;
    }
    board->print_board();
  }
};

Board_env Game::result()
{
  std::cout << "result---\n";
  board->print_board();

  Board_env winner_stone = board->define_winner();

  if (winner_stone == Board_env::blank) {
    std::cout << "draw\n";
  } else if (winner_stone == Board_env::black) {

    std::cout << "winner is black\n";
    std::cout << player_name[winner_stone] << '\n';

  } else if (winner_stone == Board_env::white) {

    std::cout << "winner is white\n";
    std::cout << player_name[winner_stone] << '\n';

  } else {
    std::cout << "no winner no draw";
    throw("no winner no draw");
  }
  return winner_stone;
}
