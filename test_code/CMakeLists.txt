cmake_minimum_required(VERSION 2.8.0)
project(othello_test_code)

include_directories(include)

add_executable(NeuralNetwork_test
  src/NeuralNetwork.cpp
  src/NeuralNetworktest.cpp
)

add_executable(ConvolutionPooling_test
  src/ConvolutionPooling.cpp
  src/ConvolutionPoolingtest.cpp
)
