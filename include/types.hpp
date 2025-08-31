#pragma once
#include <vector>

struct Point2D { double x{}, y{}; };

struct Pedestrian {
    int pedestrian_id;
    std::vector<double> obs_x_traj;
    std::vector<double> obs_y_traj;
    std::vector<double> gt_x_traj;
    std::vector<double> gt_y_traj;
    std::vector<double> pred_x_traj;
    std::vector<double> pred_y_traj;
};

using StepData = std::vector<Pedestrian>;
