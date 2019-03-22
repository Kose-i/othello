#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include <vector>
#include <random>

/*3層ニューラルネットワーク*/

class NeuralNetwork{
  private:
    std::random_device rnd;
    std::vector<std::vector<double>> w0;
    std::vector<std::vector<double>> w1;
    void init_w0();
    void init_w1();
    std::vector<double> forward_w0(const std::vector<double>&)const;
    std::vector<double> forward_w1(const std::vector<double>&)const;
    double sigmoid(const double& x)const;
    double alpha = 0.1; //study rate
    double err_thread = 1;
    void update_w0(double, std::vector<double>, std::vector<double>,double);
    void update_w1(double, std::vector<double>, std::vector<double>,std::vector<double>, double);
  public:
    NeuralNetwork(const int& size);
    ~NeuralNetwork();
    void fit(const std::vector<std::vector<double>>& input_prob, const std::vector<double>& input_answer);
    double predict(const std::vector<double>& input_prob)const;

    void print_w0()const;
    void print_w1()const;
};
#endif
