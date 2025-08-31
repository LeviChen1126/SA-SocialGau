#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Args {
public:
    int obs_len;           // 觀測長度
    int pred_len;          // 預測長度
    double init_amp;       // 初始振幅
    double init_sig;       // 初始標準差
    double learning_rate;  // 學習率

    Args() : obs_len(8), pred_len(8), init_amp(0.02), init_sig(0.1), learning_rate(0.000001) {
        std::cout << "\n(Obs, Pred)=(" << obs_len << ", " << pred_len << "), "
                  << "Learning Rate: " << std::fixed << std::setprecision(6) << learning_rate << ", "
                  << "Init_Amp: " << std::fixed << std::setprecision(5) << init_amp << ", "
                  << "Init_Sig: " << init_sig << std::endl;
    }

    static std::vector<std::string> getDatasetPaths(int pred_len);
};
