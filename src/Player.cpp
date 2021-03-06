#include "Player.hpp"

#include <iostream>
#include <istream>
#include <utility>
#include <string>
#include <memory>

#include "Board.hpp"
#include "Point.hpp"

Player::Player(std::shared_ptr<Board>& board, const Board_env& player_color) :board_state(board), my_stone_color(player_color)
{};
Player::~Player(){};
void Player::init(){};

bool isdigit(const std::string& str)
{
  if(str.size() > 1)return false;
  if("0" <= str && str <= "9")return true;
  return false;
}

Point Player::define_spot()
{
  std::vector<Point> put_able = board_state->put_able_spot(my_stone_color);
  if(put_able.size() == 0) {
    return Point(-1,-1);
  }
  Point pos;
  bool find = false;
  do{
    std::cout << "you put is only x-y" << '\n';
    for (const auto& e : put_able) {
      std::cout << "x:" << e.get_x() << ", y:"<< e.get_y() << '\n';
    }
    std::cout << "what your hand ? x: - y :(exam'2 3')";
    std::string str,str2;
    std::cin >> str >> str2;
    if(!isdigit(str) || !isdigit(str2))continue;
    pos.set_x(std::stoi(str));
    pos.set_y(std::stoi(str2));
    std::cout << "check\n";
    for (const auto& e : put_able) {
      if (pos == e) {
        find = true;
        break;
      }
    }
  }while(find == false);
  return pos;
}
