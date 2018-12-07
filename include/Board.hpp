#ifndef OTHELLO_BOARD_HPP
#define OTHELLO_BOARD_HPP

#include <bitset>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

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
    std::vector<Point> eight_direction{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

  private://function
    bool is_map_edge(const Point& pos, const Point& move)const;

  public:
    Board();
    ~Board();

    void init();
    void put_stone(const Point& , const Board_env&);

    void print_board()const;
    std::vector<Point> put_able_spot(const Board_env&)const;
    bool map_edge(const Point&)const;
    std::bitset<8> judge_direction(const Point&, const Board_env&) const;
    Board_env get_board_env(const Point&);

    Board_env define_enemy_color(const Board_env&)const;
    Board_env define_winner()const;

};

#endif
