#include <iostream>
#include <vector>

class Neural_network{
  private:
    std::vector<double> w;
  public:
    Neural_network(const int& input_size):w(input_size + 1) {};
    void print_w()const {
      for (const auto& e : w) {
        std::cout << ' ' << e;
      }
      std::cout << '\n';
    }
    void fit(const std::vector<int>& input, const std::vector<int>& answer_input) {
    }
};
int main(int argc, char** argv) {
  constexpr int input_param_count{3};
  Neural_network test(input_param_count);
  test.print_w();
}
