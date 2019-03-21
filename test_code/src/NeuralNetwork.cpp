#include "NeuralNetwork.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <numeric>//accumulate
#include <cmath>//std::expr

void NeuralNetwork::init_w0(){

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_real_distribution<> dist(-1.0, 1.0);
  for (auto& e : w0) {
    for (auto& f : e) {
      f = dist(engine);
    }
  }
}

void NeuralNetwork::init_w1(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_real_distribution<> dist(-1.0, 1.0);
  for (auto& e : w1) {
    for (auto& f : e) {
      f = dist(engine);
    }
  }
}

std::vector<double> NeuralNetwork::forward_w0(const std::vector<double>& input_prob)const {
  std::vector<double> output(input_prob.size(), 0);
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
      if (i == w0[0].size()) {
        output[j] += w0[i][j];
      } else {
        output[i] += w0[i][j]*input_prob[j];
      }
    }
  }
  return output;
}

std::vector<double> NeuralNetwork::forward_w1(const std::vector<double>& input_prob) const{
  std::vector<double> output(input_prob.size(), 0);
  for (auto i = 0;i < w1.size();++i) {
    for (auto j = 0;j < w1[0].size();++j) {
      if (i == w1[0].size()) {
        output[j] += w1[i][j];
      } else {
        output[i] += w1[i][j]*input_prob[j];
      }
    }
  }
  return output;
}

double NeuralNetwork::sigmoid(const double& x) const{
  return (1/1+std::exp(-x));
}

void NeuralNetwork::update_w0(predict_ans, tyuukansou, input_prob[i], input_answer[i]) {
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
      if (i == w0.size() - 1) {
      } else {
        w0[i][j] += alpha * e * 
      }
    }
  }
}
void NeuralNetwork::update_w1(predict_ans, tyuukansou, outputsou, input_prob[i], input_answer[i]) {
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
    }
  }
}
NeuralNetwork::NeuralNetwork(const int& size):w0(size + 1, std::vector<double>(size)), w1(size + 1,std::vector<double>(size)){
  init_w0();
  init_w1();
}
NeuralNetwork::~NeuralNetwork(){}
void NeuralNetwork::fit(const std::vector<std::vector<double>>& input_prob, const std::vector<double>& input_answer){
  double err = 10000;//double max
  while (err > err_thread) {
    for (auto i = 0;i < input_prob.size();++i) {
      std::vector<double> tyuukansou = forward_w0(input_prob[i]);
      std::vector<double> outputsou = forward_w1(tyuukansou);
      predict_ans = std::accumulate(outputsou.begin(), outputsou.end(), 0.0);
      update_w0(predict_ans, tyuukansou, input_prob[i], input_answer[i]);
      update_w1(predict_ans, tyuukansou, outputsou, input_prob[i], input_answer[i]);
      err += (input_answer[i] - predict_ans)*(input_answer[i] - predict_ans);
    }
  }
}

double NeuralNetwork::predict(const std::vector<double>& input_prob)const{
  std::vector<double> tyuukansou = forward_w0(input_prob);
  std::vector<double> outputsou = forward_w1(tyuukansou);
  return std::accumulate(outputsou.begin(), outputsou.end(), 0.0);
}

void NeuralNetwork::print_w0()const{
  for (const auto& e : w0) {
    for (const auto& f : e) {
      std::cout << f << ' ';
    }
  }
  std::cout << '\n';
}
void NeuralNetwork::print_w1()const{
  for (const auto& e : w1) {
    for (const auto& f : e) {
      std::cout << f << ' ';
    }
  }
  std::cout << '\n';
}
