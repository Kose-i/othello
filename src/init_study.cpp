#include "Game.hpp"
#include "CalcCost.hpp"

int set_count(char* argv) {
  int count {};
  for (auto i = 0;argv[i] != '\0';++i) {
    if (!(0 <= argv[i] && argv[i] <= 9)) {
      return -1;
    } else {
      count *= 10;
      count += argv[i] - '0';
    }
  }
  return count;
}

int main(int argc, char** argv) {
  int set_count {};
  if (argc != 2) {
    set_count = 10;
  } else {
    set_count = translate_int(argv[1]);
    if (set_count <= 0) {
      std::cout << "Stop\n";
    }
  }
  for (auto i = 0;i < set_count;++i) {
  }
}
