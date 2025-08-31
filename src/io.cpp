#include "io.hpp"
#include <fstream>
#include <stdexcept>
#include <json/json.h>

void loadJson(const std::string& path, std::vector<StepData>& dataset) {
    std::ifstream file(path, std::ifstream::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + path);
    }
    Json::Value root;
    file >> root;
    if (root.isNull() || !root.isArray()) {
        throw std::runtime_error("Invalid JSON format in file: " + path);
    }
    dataset.clear();
    for (const auto& step : root) {
        StepData step_data;
        for (const auto& ped : step) {
            Pedestrian p;
            p.pedestrian_id = ped["pedestrian_id"].asInt();
            for (const auto& x : ped["obs_x_traj"]) p.obs_x_traj.push_back(x.asDouble());
            for (const auto& y : ped["obs_y_traj"]) p.obs_y_traj.push_back(y.asDouble());
            for (const auto& x : ped["gt_x_traj"])  p.gt_x_traj.push_back(x.asDouble());
            for (const auto& y : ped["gt_y_traj"])  p.gt_y_traj.push_back(y.asDouble());
            step_data.push_back(std::move(p));
        }
        dataset.push_back(std::move(step_data));
    }
}

std::string get_default_dataset_path() {
    return "datasets/eth.json";
}
