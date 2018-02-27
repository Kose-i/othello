#include "Player.hpp"

#include <iostream>
#include <istream>
#include <utility>

#include "Board.hpp"

std::istream& operator>>(std::istream& is , Point& pos)
{
  std::cin >> pos.first >> pos.second;
  return is;
}

Player::Player(class Board& board) :val(&board), player_stone(Board_env::black){};
Player::~Player(){};

void Player::define_spot()
{
  std::vector<Point> put_able = val->put_able_spot(player_stone);
  Point pos;
  bool find = false;
  do{
    std::cout << "what your hand ? x - y\n";
    std::cin >> pos;
    for (const auto& e : put_able)
    {
      if (e == pos)
      {
        find = true;
        break;
      }
    }
  }
  while(find == false);
  val->put_stone(pos,player_stone);
}
