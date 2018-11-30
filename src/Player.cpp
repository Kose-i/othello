#include "Player.hpp"

#include <iostream>
#include <istream>
#include <utility>
#include <string>
#include <memory>

#include "Board.hpp"
#include "Point.hpp"

Player::Player(std::shared_ptr<Board>& board, const Board_env& player_color) :board_state(board), my_stone_color(player_color){};
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
  Point pos;
  bool find = false;
  do{
    std::cout << "what your hand ? x: - y :";
    /*/
    std::cin >> pos.first;
    std::cout << "y:";
    std::cin >> pos.second;
    */
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
