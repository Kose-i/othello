#include "Board.hpp"

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>

#include "Point.hpp"

Board::Board()  :board(8, std::vector<Board_env>(8,Board_env::blank))
{
  board[3][3] = board[4][4] = Board_env::white;
  board[3][4] = board[4][3] = Board_env::black;
};

/*
Board::Board(class Board* cp) : board(&cp)
{};
*/
Board::~Board(){};

void Board::print_board() const
{
  std::cout << " 01234567 -> x\n";
  for (int i = 0;i < 8;++i)
  {
    std::cout << i;
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
  std::vector<Point> putable_pos_box;
  Point pos = {0,0};
  for (int i = 0;i < 8;++i)
  {
    pos.second = i;
    for (int j = 0;j < 8;++j)
    {
      pos.first = j;
      if(board[i][j] != Board_env::blank)continue;
      std::bitset<8> judge = judge_direction(pos,my_color);
      if(!judge.none())putable_pos_box.push_back(pos);
    }
  }
  return putable_pos_box;
}

//std::vector<Point> Board::eight_direction{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
/*
012
3*4
567
*/

bool Board::move_direction_map_edge(const Point& pos, const Point& move_direction)
{
  if (0)
  else if (get_x(pos) == 0 && get_x(move_direction) == -1)return true;
  else if (get_y(pos) == 0 && get_y(move_direction) == -1)return true;
  else if (get_x(pos) == 7 && get_x(move_direction) == 1)return true;
  else if (get_y(pos) == 7 && get_y(move_direction) == 1)return true;

  return false;
}

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

    if ( board[get_y(new_pos)][get_x(new_pos)] != enemy_color) {
      judge[i] = false;
      continue;
    } else if(move_map_edge(new_pos, eight_direction[i])) {
      judge[i] = false;
      continue;
    }
    do{
      new_pos += eight_direction[i];
      if(move_map_edge(new_pos, eight_direction[i]))break;
    }while (board[get_y(new_pos)][get_x(new_pos)] == enemy_color);
    if(board[get_y(new_pos)][get_x(new_pos)] != my_color) {
      judge[i] = false;
    }
  }
  return judge;
}

Board_env Board::define_winner()
{
  int black_count = 0;
  int white_count = 0;
  for (const auto& e : board)
  {
    for (const auto& f : e)
    {
      if (f == Board_env::black)++black_count;
      else if (f == Board_env::white)++white_count;
    }
  }

  std::cout << 'B' << black_count << '-' << white_count << 'W' << '\n';

  if (black_count < white_count)return Board_env::white;
  else if (black_count > white_count)return Board_env::black;
  else return Board_env::blank;
}
