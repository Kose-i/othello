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
      f = dist(engine)*10;
    }
  }
}

void NeuralNetwork::init_w1(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_real_distribution<> dist(-1.0, 1.0);
  for (auto& e : w1) {
    for (auto& f : e) {
      f = dist(engine)*10;
    }
  }
}

std::vector<double> NeuralNetwork::forward_w0(const std::vector<double>& input_prob)const {
  std::vector<double> output(input_prob.size(), 0);
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
      if (i == w0[0].size()) {
        output[j] += sigmoid(w0[i][j]*1);
      } else {
        output[i] += sigmoid(w0[i][j]*input_prob[j]);
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
        output[j] += sigmoid(w1[i][j]);
      } else {
        output[i] += sigmoid(w1[i][j]*input_prob[j]);
      }
    }
  }
  return output;
}

double NeuralNetwork::sigmoid(const double& x) const{
  return (1/(1+std::exp(-x)));
}

void NeuralNetwork::update_w0(double predict_ans,std::vector<double> tyuukansou,std::vector<double> input_prob,double input_answer) {
  double diff_ans = ( input_answer - predict_ans ) * predict_ans * (1 - predict_ans);
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
      if (i == w0.size() - 1) {
        w0[i][j] += alpha * (-1.0) * diff_ans;
      } else {
        w0[i][j] -= alpha * diff_ans * tyuukansou[j];
      }
    }
  }
}
void NeuralNetwork::update_w1(double predict_ans, std::vector<double> tyuukansou, std::vector<double> outputsou, std::vector<double> input_prob, double input_answer) {
  for (auto i = 0;i < w0.size();++i) {
    for (auto j = 0;j < w0[0].size();++j) {
      double diff_ans = ( input_answer - predict_ans ) * predict_ans * (1 - predict_ans) * tyuukansou[j];
      if (i == w0.size() - 1) {
        w0[i][j] += alpha * (-1.0) * diff_ans;
      } else {
        w0[i][j] += alpha * diff_ans * tyuukansou[j];
      }
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
      std::cout << "outputsou:";
      for (auto e : outputsou) {
        std::cout << e << ' ';
      }
      std::cout << '\n';
      double predict_ans = sigmoid(std::accumulate(outputsou.begin(), outputsou.end(), 0.0));
      std::cout << "predict:" << predict_ans << '\n';
      update_w0(predict_ans, tyuukansou, input_prob[i], input_answer[i]);
      update_w1(predict_ans, tyuukansou, outputsou, input_prob[i], input_answer[i]);
      err += (input_answer[i] - predict_ans)*(input_answer[i] - predict_ans);
    }
    std::cout << "err:" << err << '\n';
    print_w0();
    print_w1();
  }
}

double NeuralNetwork::predict(const std::vector<double>& input_prob)const{
  std::vector<double> tyuukansou = forward_w0(input_prob);
  std::vector<double> outputsou = forward_w1(tyuukansou);
  return sigmoid(std::accumulate(outputsou.begin(), outputsou.end(), 0.0));
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
