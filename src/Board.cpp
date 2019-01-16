#include "Board.hpp"

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>

#include "Point.hpp"

Board::Board()  :board(8, std::vector<Board_env>(8,Board_env::blank))
{};

Board::~Board(){};

void Board::init()
{
  board[3][3] = board[4][4] = Board_env::white;
  board[3][4] = board[4][3] = Board_env::black;
}

void Board::put_stone(const Point& pos ,const Board_env& my_color)
{
  board[pos.get_y()][pos.get_x()] = my_color;
  const std::bitset<8> judge = judge_direction(pos,my_color);
  for (int i = 0;i < 8;++i)
  {
    if(judge[i])
    {
      Point new_pos = eight_direction[i] + pos;
      while(board[new_pos.get_y()][new_pos.get_x()] != my_color)
      {
        board[new_pos.get_y()][new_pos.get_x()] = my_color;
        new_pos += eight_direction[i];
      }
    }
  }
}

void Board::print_board() const
{
  std::cout << " 01234567 -> x\n";
  auto y = 0;
  for (auto e : board) {
    std::cout << y;
    ++y;
    for (auto f : e) {

      switch (f) {
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


std::vector<Point> Board::put_able_spot(const Board_env& my_color) const
{
  std::vector<Point> putable_pos_box;
  Point pos{0,0};
  for (int i = 0;i < 8;++i)
  {
    pos.set_y(i);
    for (int j = 0;j < 8;++j)
    {
      pos.set_x(j);
      if(board[i][j] != Board_env::blank)continue;
      std::bitset<8> judge = judge_direction(pos,my_color);
      if(!judge.none())putable_pos_box.push_back(pos);
    }
  }
  return putable_pos_box;
}

bool Board::map_edge(const Point& pos) const
{
  return (pos.get_x() == 0 || pos.get_x() == 7) || (pos.get_y() == 0 || pos.get_y() == 7);
}

Board_env Board::get_board_env(const Point& pos) const
{
  return board[pos.get_y()][pos.get_x()];
}

std::bitset<8> Board::judge_direction(const Point& pos , const Board_env& my_color)const
{
  std::bitset<8> judge("11111111");
  if (pos.get_x() == 0)judge[0] = judge[3] = judge[5] = false;
  else if (pos.get_x() == 7)judge[2] = judge[4] = judge[7] = false;
  if (pos.get_y() == 0)judge[0] = judge[1] = judge[2] = false;
  else if (pos.get_y() == 7)judge[5] = judge[6] = judge[7] = false;

  Board_env enemy_color = define_enemy_color(my_color);
  for (int i = 0;i < 8;++i)
  {
    if(!judge[i])continue;
    Point new_pos =   pos;
    new_pos += eight_direction[i];

    if ( board[new_pos.get_y()][new_pos.get_x()] != enemy_color) {
      judge[i] = false;
      continue;
    } else if(is_map_edge(new_pos, eight_direction[i])) {
      judge[i] = false;
      continue;
    }
    do{
      new_pos += eight_direction[i];
      if(is_map_edge(new_pos, eight_direction[i]))break;
    }while (board[new_pos.get_y()][new_pos.get_x()] == enemy_color);
    if(board[new_pos.get_y()][new_pos.get_x()] != my_color) {
      judge[i] = false;
    }
  }
  return judge;
}

Board_env Board::define_enemy_color(const Board_env& my_color)const
{
  if(my_color == Board_env::black)return Board_env::white;
  else return Board_env::black;
}

Board_env Board::define_winner()const
{
  int black_count{};
  int white_count{};
  for (const auto& e : board) {
    for (const auto& f : e) {
      if (f == Board_env::black)++black_count;
      else if (f == Board_env::white)++white_count;
    }
  }

  std::cout << 'B' << black_count << '-' << white_count << 'W' << '\n';

  if (black_count < white_count)return Board_env::white;
  else if (black_count > white_count)return Board_env::black;
  else return Board_env::blank;
}

bool Board::is_map_edge(const Point& pos, const Point& move_direction)const
{
  if (false);
  else if (pos.get_x() == 0 && move_direction.get_x() == -1)return true;
  else if (pos.get_y() == 0 && move_direction.get_y() == -1)return true;
  else if (pos.get_x() == 7 && move_direction.get_x() ==  1)return true;
  else if (pos.get_y() == 7 && move_direction.get_y() ==  1)return true;

  return false;
}

