#include <iostream>

#include "Game.hpp"

int main(int argc, char** argv)
{
  try {
    Game game_;
    game_.init();
    game_.run();
    game_.result();
  } catch(...) {
    std::cerr << "error happen\n";
    return -1;
  }
  return 0;
}
