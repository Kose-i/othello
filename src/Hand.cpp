#include "Hand.hpp"

#include <vector>
#include <utility>

#include "Board.hpp"
#include "Point.hpp"

Hand::Hand(class Board& board_val_, const Board_env& stone_color) :board_state(board_val_), my_stone_color(stone_color)
{};

Hand::~Hand(){};

Point Hand::define_spot()
{
  return Point{};
};
