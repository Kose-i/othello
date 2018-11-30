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
    auto first = s1.find("Black");
    player_name[Board_env::black] = s1.substr(first + 6);

    first = s2.find("White");
    player_name[Board_env::white] = s2.substr(first + 6);

  } else if (s1.find("White") && s2.find("Black")) {
    auto first = s2.find("Black");
    player_name[Board_env::black] = s2.substr(first + 6);

    first = s1.find("White");
    player_name[Board_env::white] = s1.substr(first + 6);

  } else {
    std::cout << "require tag\n" << "Black\n" << "white\n";
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
    players[Board_env::black] = dynamic_cast<Hand*>(new Computer(board,Board_env::black));
  } else {
    players[Board_env::black] = dynamic_cast<Hand*>(new Player(board,Board_env::black));
  }

  if(player_name[Board_env::white].find("computer") != std::string::npos) {
    players[Board_env::white] = dynamic_cast<Hand*>(new Computer(board,Board_env::black));
  } else {
    players[Board_env::white] = dynamic_cast<Hand*>(new Player(board, Board_env::white));
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

void Game::result()
{
  Board_env winner_stone = board->define_winner();

  std::cout << "result---\n";
  board->print_board();

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
