#ifndef ConvolutionPooling_hpp
#define ConvolutionPooling_hpp

#include <vector>

class ConvolutionPooling{
  private:
    const unsigned INPUTSIZE = 11;
    const unsigned FILTERSIZE = 3;
    const unsigned POOLSIZE = 3;
    const unsigned POOLOUTSIZE = 3;
    std::vector<std::vector<double>> filter;//[FILTERSIZE][FILTERSIZE]
  public:
    ConvolutionPooling();
    void conv(const std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
    double calc_conv(const std::vector<std::vector<double>>&, const int& x_pos_start, const int& y_pos_start);
    void conv_result(const std::vector<std::vector<double>>&);
    void pooling(const std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
    double maxPooling(const std::vector<std::vector<double>>&, const int& x_pos_start, const int& y_pos_start);
    void pool_result(const std::vector<std::vector<double>>&);
  private:
};
#endif
