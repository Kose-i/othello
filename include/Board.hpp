#ifndef OTHELLO_BOARD_HPP
#define OTHELLO_BOARD_HPP

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>

#include "Point.hpp"

enum class Board_env
{
    blank,
    black,
    white
};

class Board
{
  private:
    std::vector<std::vector<Board_env>> board;
  public:
    Board();
//    Board(const class Board*);
    ~Board();
    void print_board()const;
    Board_env define_enemy_color(const Board_env&);
    std::bitset<8> judge_direction(const Point&, const Board_env&);
    void put_stone(const Point& , const Board_env&);
    std::vector<Point> eight_direction{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    bool map_edge(const Point&);
    bool move_map_edge(const Point& pos, const Point& move);
    std::vector<Point> put_able_spot(const Board_env&);
    Board_env define_winner();
};

#endif
