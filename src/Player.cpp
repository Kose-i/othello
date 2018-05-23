#include "Player.hpp"

#include <iostream>
#include <istream>
#include <utility>
#include <string>

#include "Board.hpp"

std::istream& operator>>(std::istream& is , Point& pos)
{
  std::cin >> pos.first >> pos.second;
  return is;
}

Player::Player(class Board& board, const Board_env& player_color) :val(&board), player_stone(player_color){};
Player::~Player(){};

bool isdigit(const std::string& str)
{
  if(str.size() > 1)return false;
  if("0" <= str && str <= "9")return true;
  return false;
}
void Player::define_spot()
{
  std::vector<Point> put_able = val->put_able_spot(player_stone);
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
    pos.first = std::stoi(str);
    pos.second = std::stoi(str2);
    std::cout << "check\n";
    for (const auto& e : put_able)
    {
      if (e == pos)
      {
        find = true;
        break;
      }
    }
  }while(find == false);
  val->put_stone(pos,player_stone);
}
