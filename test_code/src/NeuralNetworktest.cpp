#include "NeuralNetwork.hpp"
#include <vector>
#include <iostream>

int main(int argc, char** argv) {
  NeuralNetwork test;
  std::vector<std::vector<double>> input_data_prob {{1,1,1},{1,0,1},{0,0,1},{0,0,0}};
  std::vector<double> answer_input {1,1,0,0};
  std::cout << "before fit\n";
  test.print();
  test.fit(input_data_prob, answer_input);
  std::cout << "after fit\n";
  test.print();
  std::cout << "test predict:";
  std::vector<double> input_test(3);
  std::cin >> input_test[0] >> input_test[1] >> input_test[2];
  std::cout << test.predict(input_test) << '\n';
}
