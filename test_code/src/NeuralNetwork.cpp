#include "NeuralNetwork.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <cassert>

double NeuralNetwork::ALPHA = 10.0;
unsigned NeuralNetwork::INPUTNO = 3;
unsigned NeuralNetwork::HIDDENNO= 3;
unsigned NeuralNetwork::SEED =65535;
unsigned NeuralNetwork::MAXINPUTNO = 100;
unsigned NeuralNetwork::BIGNUM =100;
double NeuralNetwork::LIMIT = 0.001;
  /*
     std::vector<std::vector<double>> wh;//[HIDDENNO][INPUTNO+1]
     std::vector<double> wo;//[HIDDENNO+1]
   */

void NeuralNetwork::initwh() {//中間層の重みの初期化
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_real_distribution<> dist(-1.0, 1.0);

  for (auto e : wh) {
    for (auto f : e) {
      f = dist(engine);
    }
  }
}

void NeuralNetwork::initwo() {//出力層の重みの初期化
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_real_distribution<> dist(-1.0, 1.0);

  for (auto e : wo) {
    e = dist(engine);
  }
}

void NeuralNetwork::print(void)const {
  std::cout << "wh:";
  for (const auto& e : wh) {
    for (const auto& f : e) {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "wo:";
  for (const auto& e : wo) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

double NeuralNetwork::forward(const std::vector<double>& input_problem, std::vector<double>& tyuukansou_output) const{
  assert(input_problem.size() == INPUTNO);
  assert(tyuukansou_output.size() == HIDDENNO);

 for(auto i=0;i<HIDDENNO;++i) {
  double u = 0.0;
  for(auto j=0;j<INPUTNO;++j) {
    u += input_problem[j]*wh[i][j]; 
  }
  u -= wh[i][INPUTNO];
  tyuukansou_output[i] = f(u);
 }

 double o = 0;
 for(auto i=0;i<HIDDENNO;++i) {
   o += tyuukansou_output[i]*wo[i];
 }
 o -= wo[HIDDENNO];
 
 return f(o);
}

void NeuralNetwork::olearn(const std::vector<double>& input_problem, const double& input_ans, const std::vector<double>& tyuukansou_output, const double& predict_ans) {

  double d=(input_ans-predict_ans)*predict_ans*(1-predict_ans);

  for(auto i = 0;i < HIDDENNO;++i) {
    wo[i] += ALPHA * tyuukansou_output[i] * d;
  }

  wo[HIDDENNO] += ALPHA * (-1.0) * d;
}

void NeuralNetwork::hlearn(const std::vector<double>& input_problem, const double& input_ans, const std::vector<double>& tyuukansou_output, const double& predict_ans) {

  for(auto j=0;j<HIDDENNO;++j) {
    double dj = tyuukansou_output[j] * (1-tyuukansou_output[j]) * wo[j] * (input_ans - predict_ans) * predict_ans * (1-predict_ans) ;
    for(auto i=0;i<INPUTNO;++i) {
      wh[j][i] += ALPHA * input_problem[i] * dj ;
    }
    wh[j][INPUTNO] += ALPHA * (-1.0) * dj ;
  }

}


double NeuralNetwork::f(const double& u)const {
 return 1.0/(1.0+std::exp(-u)) ;
}
NeuralNetwork::NeuralNetwork():wo(HIDDENNO+1), wh(HIDDENNO,std::vector<double>(INPUTNO+1)) {};
void NeuralNetwork::fit(const std::vector<std::vector<double>>& input_prob_box, const std::vector<double>& input_ans_box) {
  initwh();
  initwo();
  print();

  double err = std::numeric_limits<double>::max();

  while (err > LIMIT) {
    err = 0.0;
    for (auto i = 0;i < input_prob_box.size();++i) {
      std::vector<double> tyuukansou_output(HIDDENNO);
      double o = forward(input_prob_box[i], tyuukansou_output);
      olearn(input_prob_box[i], input_ans_box[i], tyuukansou_output, o);
      hlearn(input_prob_box[i], input_ans_box[i], tyuukansou_output, o);
      err += (o - input_ans_box[i])*(o - input_ans_box[i]);
    }
    std::cout << "err:" << err << '\n';
  }
  std::cout << "fit finish\n";
}
double NeuralNetwork::predict(const std::vector<double>& input_prob) const {
  std::vector<double> tmp(HIDDENNO);
  return forward(input_prob, tmp);
}

