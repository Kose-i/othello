#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include <iostream>
#include <vector>
#include <cmath>

class NeuralNetwork{
  private:
    static double ALPHA;
    static unsigned INPUTNO;
    static unsigned HIDDENNO;
    static unsigned SEED;
    static unsigned MAXINPUTNO;
    static unsigned BIGNUM;
    static double LIMIT;

    std::vector<std::vector<double>> wh;//[HIDDENNO][INPUTNO+1]
    std::vector<double> wo;//[HIDDENNO+1]

    double f(const double& u)const;//sigmoid
    void initwh();//中間層の重みの初期化
    void initwo();//出力層の重みの初期化
    double forward(const std::vector<double>& input_problem, std::vector<double>& tyuukansou_output)const;
    void olearn(const std::vector<double>& input_problem, const double& input_ans, const std::vector<double>& tyuukansou_output, const double& predict_ans);
    void hlearn(const std::vector<double>& input_problem, const double& input_ans, const std::vector<double>& tyuukansou_output, const double& predict_ans);
  public:
    NeuralNetwork();
    void fit(const std::vector<std::vector<double>>& input_prob_box, const std::vector<double>& input_ans_box);
    double predict(const std::vector<double>& input_prob)const;
    void print(void)const;//wh, wo の表示

};
#endif
