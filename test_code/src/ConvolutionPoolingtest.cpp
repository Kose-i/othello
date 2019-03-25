#include "ConvolutionPooling.hpp"

#include <vector>
#include <iostream>

int main(int argc, char** argv) {
  std::vector<std::vector<double>> input_data{
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0}};

  ConvolutionPooling model;
  std::vector<std::vector<double>> output_conv_data(11,std::vector<double>(11));
  model.conv(input_data, output_conv_data);
  std::cout << "conv_result:\n";
  model.conv_result(output_conv_data);

  std::vector<std::vector<double>> pooling_output_data(3,std::vector<double>(3));
  model.pooling(output_conv_data, pooling_output_data);
  std::cout << "pooling_result:\n";
  model.pool_result(pooling_output_data);
}
