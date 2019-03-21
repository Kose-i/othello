#include "NeuralNetwork.hpp"
#include <vector>

int main(int argc, char** argv) {
  NeuralNetwork test(3);
  std::vector<std::vector<double>> input_data_prob {{1,1,1},{1,0,1},{0,0,1},{0,0,0}};
  std::vector<double> answer_input {1,1,0,0};
  test.fit(input_data_prob, answer_input);
  test.print_w0();
  test.print_w1();
}
