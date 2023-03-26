// author: Raphael Enßlin

#pragma once
#include <vector>

namespace properties
{
    void RenderUI();
    void RenderTables();
    void DrawPerceptron();
    double Predict(std::vector<int>);
    double Step(double i);
    void Fit();
    bool Test();

    static int exp_res = 0;
    static int nodes = 2;
    static double learnrate = 0.5;
    static double thresh = 1;
    static bool elOne = true;
    static bool elTwo = true;
    static bool relTraining = true;
    static bool advanced = false;
    static bool autoAdjustLearnrate = true;

    static std::vector<int> values;
    static std::vector<double> weights;
}
