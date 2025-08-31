#pragma once
#include "types.hpp"
#include <vector>

struct SDData {
    double curr_x{};
    double curr_y{};
    double pred_x{};
    double pred_y{};
    double theta_x{};
    double theta_y{};
    double Gx{};
    double Gy{};
    double sig{};
    double amp{};
};

double cal_amp(std::vector<Pedestrian>& step,
               std::vector<SDData>& sd_mem,
               int p_id,
               bool check_step1,
               double init_amp,
               double learning_rate);
