#include "Game.hpp"
#include "CalcCost.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "error: argc != 2\n";
    return 1;
  }
  int set_count = translate_int(argv[1]);
  if (set_count <= 0) {
    std::cerr << "set_count <= 0 || Invalid Number\n";
    return 1;
  } else if (set_count < 10) {
    std::cout << "This count is too small\n";
    return 1;
  }
  for (auto i = 0;i < set_count;++i) {
  }
}
