#include "Board.hpp"

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>

using Point = std::pair<int,int>;

Point& operator+=(Point& pos1, const Point& pos2)
{
  pos1.first += pos2.first;
  pos1.second += pos2.second;
  return pos1;
}

Point operator+(const Point& pos1, const Point& pos2)
{
  Point ans_pos = pos1;
  ans_pos += pos2;
  return ans_pos;
}

int Board::get_x(const Point& pos)
{
  return pos.first;
}
int Board::get_y(const Point& pos)
{
  return pos.second;
}

int& Board::set_x(Point& pos)
{
  return pos.first;
}
int& Board::set_y(Point& pos)
{
  return pos.second;
}

Board::Board() : board(8,std::vector<Board_env>(8,Board_env::blank))
{
  board[3][3] = board[4][4] = Board_env::black;
  board[3][4] = board[4][3] = Board_env::white;
};

/*
Board::Board(class Board* cp) : board(&cp)
{};
*/
Board::~Board(){};

void Board::print_board()
{
  for (int i = 0;i < 8;++i)
  {
    for (int j = 0;j < 8;++j)
    {
      switch (board[i][j])
      {
        case Board_env::black:
          std::cout << "B";
          break;
        case Board_env::white:
          std::cout << "W";
          break;
        case Board_env::blank:
          std::cout << "+";
          break;
      }
    }
    std::cout <<  '\n';
  }
}
void Board::put_stone(const Point& pos ,const Board_env& my_color)
{
  board[get_y(pos)][get_x(pos)] = my_color;
  std::bitset<8> judge = judge_direction(pos,my_color);
  for (int i = 0;i < 8;++i)
  {
    if(judge[i])
    {
      Point new_pos = pos + eight_direction[i];
      while(board[get_y(new_pos)][get_x(new_pos)] != my_color)
      {
        board[get_y(new_pos)][get_x(new_pos)] = my_color;
        new_pos += eight_direction[i];
      }
    }
  }
}

std::vector<Point> Board::put_able_spot(const Board_env& my_color)
{
  std::vector<Point> put_pos;
  Point pos = {0,0};
  for (int i = 0;i < 8;++i)
  {
    pos.first = i;
    for (int j = 0;j < 8;++j)
    {
      if(board[i][j] != Board_env::blank)continue;
      pos.second = j;
      std::bitset<8> judge = judge_direction(pos,my_color);
      if(!judge.none())put_pos.push_back(pos);
    }
  }
  return put_pos;
}

//std::vector<Point> Board::eight_direction{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
/*
012
3*4
567
*/

bool Board::map_edge(const Point& pos)
{
  return (get_x(pos) == 0 || get_x(pos) == 7) || (get_y(pos) == 0 || get_y(pos) == 7);
}

Board_env Board::define_enemy_color(const Board_env& my_color)
{
  if(my_color == Board_env::black)return Board_env::white;
  else return Board_env::black;
}

//std::vector<std::vector<Board_env>> Board::board;

std::bitset<8> Board::judge_direction(const Point& pos , const Board_env& my_color)
{
  std::bitset<8> judge("11111111");
  if (get_x(pos) == 0)judge[0] = judge[3] = judge[5] = false;
  else if (get_x(pos) == 7)judge[2] = judge[4] = judge[7] = false;
  if (get_y(pos) == 0)judge[0] = judge[1] = judge[2] = false;
  else if (get_y(pos) == 7)judge[5] = judge[6] = judge[7] = false;

  Board_env enemy_color = define_enemy_color(my_color);
  for (int i = 0;i < 8;++i)
  {
    if(!judge[i])continue;
    Point new_pos = pos + eight_direction[i];
    if ( board[get_y(new_pos)][get_x(new_pos)] != enemy_color)
    {
      judge[i] = false;
      continue;
    }
    new_pos += eight_direction[i];
    while (board[get_y(new_pos)][get_x(new_pos)] == enemy_color)
    {
      new_pos += eight_direction[i];
      if(map_edge(new_pos))break;
    }
    if(board[get_y(new_pos)][get_x(new_pos)] != my_color)
    {
      judge[i] = false;
    }
  }
  return judge;
}
