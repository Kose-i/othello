#include "ConvolutionPooling.hpp"

#include <iostream>
#include <vector>
#include <cassert>

/*
    const unsigned INPUTSIZE = 11;
    const unsigned FILTERSIZE = 3;
    const unsigned POOLSIZE = 3;
    const unsigned POOLOUTSIZE = 3;
    std::vector<std::vector<double>> filter;//[][FILTERSIZE]
*/
ConvolutionPooling::ConvolutionPooling():filter(FILTERSIZE, std::vector<double>(FILTERSIZE)) {
//TODO initializer_list use
  filter[0][0] = 0;filter[0][1] = 1;filter[0][2] = 0;
  filter[1][0] = 0;filter[1][1] = 1;filter[1][2] = 0;
  filter[2][0] = 0;filter[2][1] = 1;filter[2][2] = 0;
}

void ConvolutionPooling::conv(const std::vector<std::vector<double>>& input_data, std::vector<std::vector<double>>& conv_result) {
  assert(input_data[0].size() == INPUTSIZE);
  assert(input_data.size() == INPUTSIZE);
//  assert(conv_result.size() == INPUTSIZE);
//  assert(conv_result[0].size() == INPUTSIZE);
  unsigned startpoint = FILTERSIZE / 2;
  for (auto i = startpoint;i < INPUTSIZE - startpoint;++i) {
    for (auto j = startpoint;j < INPUTSIZE - startpoint;++j) {
      conv_result[i][j] = calc_conv(input_data, i, j);
    }
  }
}

double ConvolutionPooling::calc_conv(const std::vector<std::vector<double>>& input_data, const int& y_pos_start, const int& x_pos_start) {
  double sum {};
  for (auto i = 0;i < FILTERSIZE;++i) {
    for (auto j = 0;j < FILTERSIZE;++j) {
      sum += input_data[y_pos_start - FILTERSIZE/2 + i][x_pos_start - FILTERSIZE/2 + j]*filter[i][j];
    }
  }
  return sum;
}

void ConvolutionPooling::conv_result(const std::vector<std::vector<double>>& conv_res) {
  for (const auto& e : conv_res) {
    for (const auto& f : e) {
      std::cout << ' ' << f;
    }
    std::cout << '\n';
  }
}

void ConvolutionPooling::pooling(const std::vector<std::vector<double>>& conv_out, std::vector<std::vector<double>>& poolout) {
  assert(conv_out.size() == INPUTSIZE);
  assert(conv_out[0].size() == INPUTSIZE);
  assert(poolout.size() == POOLOUTSIZE);
  assert(poolout[0].size() == POOLOUTSIZE);
  for (auto i = 0;i < POOLOUTSIZE;++i) {
    for (auto j = 0;j < POOLOUTSIZE;++j) {
      poolout[i][j] = maxPooling(conv_out, i,j);
    }
  }

}
double ConvolutionPooling::maxPooling(const std::vector<std::vector<double>>& convout, const int& i_start, const int& j_start) {
  assert(convout.size() == INPUTSIZE);
  assert(convout[0].size() == INPUTSIZE);
  int halfpool = POOLSIZE/2;
  double max = convout[i_start*POOLOUTSIZE+1+halfpool][j_start*POOLOUTSIZE+1+halfpool];
  for(auto i=POOLOUTSIZE*i_start+1;i<=POOLOUTSIZE*i_start+1+(POOLSIZE-halfpool);++i) {
    for(auto j=POOLOUTSIZE*j_start+1;j<=POOLOUTSIZE*j_start+1+(POOLSIZE-halfpool);++j) {
      if(max<convout[i][j]) max=convout[i][j];
    }
  }
  return max;
}

void ConvolutionPooling::pool_result(const std::vector<std::vector<double>>& poolout) {
  for (const auto& e : poolout) {
    for (const auto& f : e) {
      std::cout << ' ' << f;
    }
    std::cout << '\n';
  }
}


